#include <bits/stdc++.h>
using namespace std;
char keyT[6][6];
// Function to convert the string to lowercase
void toLowerCase(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

// Function to remove all spaces in a string
void removeSpaces(string &str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

// Function to generate the 6x6 key square
void generateKeyTable(const string &key) {
    string tempKey = key;
    removeSpaces(tempKey);
    toLowerCase(tempKey);

    // Initialize the key table
    int row = 0, col = 0;
    bool filled[36] = {false};

    for (char ch : tempKey) {
        if (ch >= 'a' && ch <= 'z' || ch <= '9' && ch >= '0' && !filled[ch - 'a']) {
            keyT[row][col] = ch;
            filled[ch - 'a'] = true;
            col++;
            if (col == 6) {
                col = 0;
                row++;
            }
        }
    }

    // Fill with numbers from 0 to 9
    for (char ch = '0'; ch <= '9'; ++ch) {
        if (!filled[ch - '0' + 26]) {
            keyT[row][col] = ch;
            filled[ch - '0' + 26] = true;
            col++;
            if (col == 6) {
                col = 0;
                row++;
            }
        }
    }

    // Fill with remaining characters from 'a' to 'z'
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (!filled[ch - 'a']) {
            keyT[row][col] = ch;
            filled[ch - 'a'] = true;
            col++;
            if (col == 6) {
                col = 0;
                row++;
            }
        }
    }
}

// Function to search for the characters of a digraph
// in the key square and return their position
void search(char a, char b, int arr[])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (keyT[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

// Function to make the plain text length to be even
string prepare(string str)
{
    string result = str;
    if (str.size() % 2 != 0)
    {
        result.push_back('z');
    }
    return result;
}

// Function for performing the encryption
string encrypt(string str)
{
    int a[4];
    for (int i = 0; i < str.size(); i += 2)
    {
        search(str[i], str[i + 1], a);
        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][(a[1] + 1) % 6];
            str[i + 1] = keyT[a[0]][(a[3] + 1) % 6];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[(a[0] + 1) % 6][a[1]];
            str[i + 1] = keyT[(a[2] + 1) % 6][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
    return str;
}

// Function to encrypt using Playfair Cipher
string encryptByPlayfairCipher(string str)
{
    return encrypt(str);
}

// Function to decrypt
string decrypt(string str)
{
    int a[4];
    for (int i = 0; i < str.size(); i += 2)
    {
        search(str[i], str[i + 1], a);
        if (a[0] == a[2])
        {
            str[i] = keyT[a[0]][(a[1] - 1 + 6) % 6];
            str[i + 1] = keyT[a[0]][(a[3] - 1 + 6) % 6];
        }
        else if (a[1] == a[3])
        {
            str[i] = keyT[(a[0] - 1 + 6) % 6][a[1]];
            str[i + 1] = keyT[(a[2] - 1 + 6) % 6][a[1]];
        }
        else
        {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
    return str;
}

// Function to call decrypt
string decryptByPlayfairCipher(string str)
{
    return decrypt(str);
}

// Driver code
int main()
{
    string key;
    cin >> key;
    cout << "Key text: " << key << "\n";

    string plaintext;
    cin >> plaintext;
    cout << "Plain text: " << plaintext << "\n";
    plaintext = prepare(plaintext);
    generateKeyTable(key);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << keyT[i][j] << " ";
        }
        cout << endl;
    }

    // Encrypt using Playfair Cipher
    string encryptedText = encryptByPlayfairCipher(plaintext);
    cout << "Cipher text: " << encryptedText << "\n";

    // Decrypt using Playfair Cipher
    string decryptedText = decryptByPlayfairCipher(encryptedText);
    cout << "Decrypted text: " << decryptedText << "\n";
    return 0;
}
