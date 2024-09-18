#include <bits/stdc++.h>
using namespace std;

// Function to calculate (x^y) % n using recursion (modular exponentiation)
int power(int x, int y, int n)
{
    if (y == 0)
        return 1; // Handle case when n = 1 or y = 0

    int val = power(x, y / 2, n); // Recursively calculate power

    if (y % 2 == 0)
        return (val * val) % n; // If y is even, return (val * val) % n
    else
        return (val * val * x) % n; // If y is odd, return (val * val * x) % n
}

int main()
{
    int p = 7;
    int q = 19;

    int n = p * q;               // RSA modulus
    int phi = (p - 1) * (q - 1); // Euler's totient function

    int e = 2;
    while (__gcd(e, phi) != 1) // Find e such that gcd(e, phi) = 1
    {
        e++;
    }

    int public_key = e;

    int d = 2;
    while ((d * e) % phi != 1) // Find d such that (d * e) % phi = 1
    {
        d++;
    }

    int private_key = d;

    cout << "Public Key: " << public_key << endl;
    cout << "Private Key: " << private_key << endl;

    // The message "i love u"
    string message;
    getline(cin, message);

    vector<int> encrypted; // To store the encrypted message
    vector<int> decrypted; // To store the decrypted message

    // Encrypt each character using RSA (public key)
    for (auto ch : message)
    {
        if (ch == ' ')
        {
            encrypted.push_back(-1); // Handle spaces separately (as -1)
        }
        else
        {
            int m = (int)ch;                 // Convert character to its ASCII value
            int c = power(m, public_key, n); // Encrypt using public key
            encrypted.push_back(c);
        }
    }

    // Print the encrypted message (as integers)
    cout << "Encrypted Message: ";
    for (auto c : encrypted)
    {
        if (c == -1)
            cout << " " << " "; // Print spaces for -1
        else
            cout << char((c % 26) + 97);
    }
    cout << endl;

    // Decrypt each character using RSA (private key)
    for (auto c : encrypted)
    {
        if (c == -1)
        {
            decrypted.push_back(' '); // Handle spaces
        }
        else
        {
            int m = power(c, private_key, n); // Decrypt using private key
            decrypted.push_back(m);           // Convert back to ASCII
        }
    }

    // Print the decrypted message (as characters)
    cout << "Decrypted Message: ";
    for (auto m : decrypted)
    {
        cout << (char)m; // Convert back to character
    }
    cout << endl;

    return 0;
}
