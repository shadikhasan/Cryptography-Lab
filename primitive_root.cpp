#include <bits/stdc++.h>
using namespace std;
int Pow(int a, int b)
{
    int mul = 1;
    for(int i = 1; i <= b; i++)
    {
        mul *= a;
    }
    return mul;
}
int main()
{
    int a, p;
    cin >> a >> p;

    //cout << Pow(a, p);

    set <int> st;

    for(int i = 1; i < p; i++)
    {
        st.insert(Pow(a, i) % p);
    }

    for(auto x : st)
    {
        cout << x << " ";
    }
    cout << endl;

    if(st.size() ==  p - 1)
    {
        cout << "Yes, " << a << " is a primitive root of prime numbe " << p << endl;
    }
    else cout << "No";
}