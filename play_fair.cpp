#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
int keyT[5][5];
map<char, pair<int, int>> mp;
map<char, bool> ok;
string modify(string x)
{
    string ans = "";
    for (auto xx : x)
    {
        if (xx == ' ')
            continue;
        if (xx >= 65 and xx <= 90)
            xx += 32;
        if (xx == 'j')
            xx = 'i';
        int sz = ans.size();
        if (sz % 2 == 1 and sz > 0 and ans[sz - 1] == xx)
        {
            ans.pb('x');
            ans.pb(xx);
        }
        else
            ans.pb(xx);
    }
    if (ans.size() % 2 == 1)
        ans.pb('z');
    return ans;
}

void createTable(string key)
{
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] == 'j')
            key[i] = 'i';
        if (key[i] >= 65 and key[i] <= 90)
            key[i] += 32;
    }
    for (int i = 97; i <= 122; i++)
    {
        if (char(i) != 'j')
            key.pb(i);
    }
    int pos = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = pos; k < key.size(); k++)
            {
                if (ok[key[k]] == false)
                {
                    keyT[i][j] = key[k];
                    ok[key[k]] = true;
                    mp[key[k]] = {i, j};
                    pos++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << (char)keyT[i][j] << " ";
        cout << endl;
    }
}
string Encrypt(char a, char b)
{
    pair<int, int> p1, p2;
    p1 = mp[a], p2 = mp[b];
    string x = "";
    if (p1.ff == p2.ff)
    {
        x.pb(keyT[p1.ff][(p1.ss + 1) % 5]);
        x.pb(keyT[p1.ff][(p2.ss + 1) % 5]);
    }
    else if (p1.ss == p2.ss)
    {
        x.pb(keyT[(p1.ff + 1) % 5][p1.ss]);
        x.pb(keyT[(p2.ff + 1) % 5][p1.ss]);
    }
    else
    {
        x.pb(keyT[p1.ff][p2.ss]);
        x.pb(keyT[p2.ff][p1.ss]);
    }
    return x;
}
string Encryption(string ptext)
{
    string ans = "";
    for (int i = 0; i < ptext.size(); i += 2)
        ans += Encrypt(ptext[i], ptext[i + 1]);
    return ans;
}
int main()
{
    string key, plaintext;
    cout << "Key: ";
    cin >> key;
    cout << "Plaintext: ";
    cin >> plaintext;
    cout << key << " " << plaintext << endl;
    string ptext;
    ptext = modify(plaintext);
    cout << ptext << endl;
    createTable(key);
    string cipher = Encryption(ptext);
    cout << cipher << endl;
}
//play fair
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
int keyT[5][5];
map<char, pair<int, int>> mp;
map<char, bool> ok;
string modify(string x)
{
    string ans = "";
    for (auto xx : x)
    {
        if (xx == ' ')
            continue;
        if (xx >= 65 and xx <= 90)
            xx += 32;
        if (xx == 'j')
            xx = 'i';
        int sz = ans.size();
        if (sz % 2 == 1 and sz > 0 and ans[sz - 1] == xx)
        {
            ans.pb('x');
            ans.pb(xx);
        }
        else
            ans.pb(xx);
    }
    if (ans.size() % 2 == 1)
        ans.pb('z');
    return ans;
}

void createTable(string key)
{
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] == 'j')
            key[i] = 'i';
        if (key[i] >= 65 and key[i] <= 90)
            key[i] += 32;
    }
    for (int i = 97; i <= 122; i++)
    {
        if (char(i) != 'j')
            key.pb(i);
    }
    int pos = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = pos; k < key.size(); k++)
            {
                if (ok[key[k]] == false)
                {
                    keyT[i][j] = key[k];
                    ok[key[k]] = true;
                    mp[key[k]] = {i, j};
                    pos++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << (char)keyT[i][j] << " ";
        cout << endl;
    }
}
string Encrypt(char a, char b)
{
    pair<int, int> p1, p2;
    p1 = mp[a], p2 = mp[b];
    string x = "";
    if (p1.ff == p2.ff)
    {
        x.pb(keyT[p1.ff][(p1.ss + 1) % 5]);
        x.pb(keyT[p1.ff][(p2.ss + 1) % 5]);
    }
    else if (p1.ss == p2.ss)
    {
        x.pb(keyT[(p1.ff + 1) % 5][p1.ss]);
        x.pb(keyT[(p2.ff + 1) % 5][p1.ss]);
    }
    else
    {
        x.pb(keyT[p1.ff][p2.ss]);
        x.pb(keyT[p2.ff][p1.ss]);
    }
    return x;
}
string Encryption(string ptext)
{
    string ans = "";
    for (int i = 0; i < ptext.size(); i += 2)
        ans += Encrypt(ptext[i], ptext[i + 1]);
    return ans;
}
int main()
{
    string key, plaintext;
    cout << "Key: ";
    cin >> key;
    cout << "Plaintext: ";
    cin >> plaintext;
    cout << key << " " << plaintext << endl;
    string ptext;
    ptext = modify(plaintext);
    cout << ptext << endl;
    createTable(key);
    string cipher = Encryption(ptext);
    cout << cipher << endl;
}