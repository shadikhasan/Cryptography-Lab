#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// Predefined arrays for various operations
int key[10] = {1, 0, 1, 0, 0, 0, 0, 0, 1, 0}; // Example key
int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
int P8[8] = {6, 3, 7, 4, 8, 5, 10, 9};
int key1[8], key2[8]; // Generated keys
vector<int> IP = {2, 6, 3, 1, 4, 8, 5, 7};

int EP[8] = {4, 1, 2, 3, 2, 3, 4, 1};
int P4[4] = {2, 4, 3, 1};
int S0[4][4] = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
int S1[4][4] = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};

//

vector<int> ipInv(vector<int> v)
{
    vector<int> ans(8);
    for (int i = 1; i <= 8; i++)
    {
        ans[v[i - 1] - 1] = i;
    }
    return ans;
}

vector<int> IP_inv = ipInv(IP);

string binary_(int n)
{
    if (n == 0)
        return "00";
    else if (n == 1)
        return "01";
    else if (n == 2)
        return "10";
    else
        return "11";
}

vector<int> ff(vector<int> a, int k[])
{
    vi l(4), r(4);

    for (int i = 0; i < 4; i++)
    {
        l[i] = a[i];
        r[i] = a[i + 4];
    }

    vi ep(8);
    for (int i = 0; i < 8; i++)
    {
        ep[i] = r[EP[i] - 1];
    }

    // ep xor key
    for (int i = 0; i < 8; i++)
    {
        a[i] = ep[i] ^ k[i];
    }

    vi l1(4), r1(4);
    for (int i = 0; i < 4; i++)
    {
        l1[i] = a[i];
        r1[i] = a[i + 4];
    }

    int row = stoi(to_string(l1[0]) + to_string(l1[3]), nullptr, 2);
    int col = stoi(to_string(l1[1]) + to_string(l1[2]), nullptr, 2);

    string ls = binary_(S0[row][col]);

    row = stoi(to_string(r1[0]) + to_string(r1[3]), nullptr, 2);
    col = stoi(to_string(r1[1]) + to_string(r1[2]), nullptr, 2);

    string rs = binary_(S1[row][col]);

    string s = ls + rs;

    vi newV(4);
    for (int i = 0; i < 4; i++)
    {
        newV[i] = s[i] - 48;
    }

    // p4
    vi p4v(4);
    for (int i = 0; i < 4; i++)
    {
        p4v[i] = newV[P4[i] - 1];
    }

    // newV xor p4v
    for (int i = 0; i < 4; i++)
    {
        l[i] = p4v[i] ^ l[i];
    }

    vi output(8);
    for (int i = 0; i < 4; i++)
    {
        output[i] = l[i];
        output[i + 4] = r[i];
    }

    return output;
}
vi swap(vi a, int n)
{
    vi output(2 * n);
    for (int i = 0; i < n; i++)
    {
        output[i] = a[i + n];
        output[i + n] = a[i];
    }
    return output;
}
// Decryption function
vector<int> decryption(vector<int> ar)
{
    vector<int> arr(8);
    for (int i = 0; i < 8; i++)
    {
        arr[i] = ar[IP[i] - 1];
    }

    vector<int> arr1 = ff(arr, key2);
    vector<int> after_swap = swap(arr1, 4);
    vector<int> arr2 = ff(after_swap, key1);

    vector<int> decrypted(8);
    for (int i = 0; i < 8; i++)
    {
        decrypted[i] = arr2[IP_inv[i] - 1];
    }

    return decrypted;
}

// Encryption ff
vector<int> encryption(vector<int> plaintext)
{
    vector<int> arr(8);
    for (int i = 0; i < 8; i++)
    {
        arr[i] = plaintext[IP[i] - 1];
    }

    vector<int> arr1 = ff(arr, key1);
    vector<int> after_swap = swap(arr1, 4);
    vector<int> arr2 = ff(after_swap, key2);

    vector<int> ciphertext(8);
    for (int i = 0; i < 8; i++)
    {
        ciphertext[i] = arr2[IP_inv[i] - 1];
    }

    return ciphertext;
}

void generateKeys()
{
    vector<int> key_(10);

    // Applying P10
    for (int i = 0; i < 10; i++)
    {
        key_[i] = key[P10[i] - 1];
    }

    vector<int> l(5), r(5);
    for (int i = 0; i < 5; i++)
    {
        l[i] = key_[i];
        r[i] = key_[i + 5];
    }

    // Left shift by 1
    std::rotate(l.begin(), l.begin() + 1, l.end());
    std::rotate(r.begin(), r.begin() + 1, r.end());

    // Combine l and r using std::copy
    std::copy(l.begin(), l.end(), key_.begin());
    std::copy(r.begin(), r.end(), key_.begin() + 5);

    // Applying P8 to generate key1
    for (int i = 0; i < 8; i++)
    {
        key1[i] = key_[P8[i] - 1];
    }

    cout << "Key 1: ";
    for (auto key : key1)
    {
        cout << key << " ";
    }

    // Left shift by 2
    std::rotate(l.begin(), l.begin() + 2, l.end());
    std::rotate(r.begin(), r.begin() + 2, r.end());

    // Combine l and r again using std::copy
    std::copy(l.begin(), l.end(), key_.begin());
    std::copy(r.begin(), r.end(), key_.begin() + 5);

    // Applying P8 to generate key2
    for (int i = 0; i < 8; i++)
    {
        key2[i] = key_[P8[i] - 1];
    }

    cout << endl;
    cout << "Key 2: ";
    for (auto key : key2)
    {
        cout << key << " ";
    }
}

int main()
{
    generateKeys();

    vector<int> plaintext = {1, 0, 1, 0, 0, 0, 1, 1}; // Example plaintext

    // cout << endl;
    // vi ans = ff(plaintext, key1);

    // for (auto x : ans)
    // {
    //     cout << x << " ";
    // }

    cout << endl
         << endl
         << "Plaintext: ";
    for (int i = 0; i < 8; i++)
        cout << plaintext[i] << " ";

    // Encrypt the plaintext
    vector<int> ciphertext = encryption(plaintext);
    cout << endl
         << "Ciphertext: ";
    for (int i = 0; i < 8; i++)
        cout << ciphertext[i] << " ";

    // Decrypt the ciphertext
    vector<int> decrypted = decryption(ciphertext);
    cout << endl
         << "Decrypted text: ";
    for (int i = 0; i < 8; i++)
        cout << decrypted[i] << " ";

    return 0;
}
