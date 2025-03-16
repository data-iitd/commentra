#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    stringstream ss(a);
    string b;
    while(getline(ss,b,','))
    {
        cout<<b<<endl;
    }
    return 0;
}
