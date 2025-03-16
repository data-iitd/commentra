#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str[2];
    cin>>str[0]>>str[1];
    int a,b;
    cin>>a>>b;
    string u;
    cin>>u;
    cout<<((u==str[0])?(a-1)+" "+to_string(b):to_string(a)+" "+(b-1));
    return 0;
}
