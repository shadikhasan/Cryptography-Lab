// A C++ program to illustrate Caesar Cipher Technique
#include <bits/stdc++.h>
using namespace std;

string encrypt(string text, int k)
{
	string result = "";

	// traverse text
	for (int i = 0; i < text.length(); i++) {
		// apply transformation to each character
		// Encrypt Uppercase letters
		if (isupper(text[i]))
			result += char(int(text[i] + k - 65) % 26 + 65);

		// Encrypt Lowercase letters
		else
			result += char(int(text[i] + k - 97) % 26 + 97);
	}

	// Return the resulting string
	return result;
}

// Driver program to test the above function
int main()
{
    string s;
    cin >> s;
    int key;
    cin >> key;

    cout << "Given msg: " << s <<endl;
    string ciphertext = encrypt(s, key);
    string decryptedmsg = encrypt(ciphertext, -key);
    cout << "Cipher text: " << ciphertext << endl;
    cout << "Decrypted msg: " << decryptedmsg <<endl;

    //brute force attack to recover the original msg
    for(int i = 1; i <= 26; i++)
    {
        cout << "key:" << i << ", " << encrypt(ciphertext, -i) << endl;
    }
	return 0;
}
