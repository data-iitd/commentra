#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[0]) a++;
            else if(s[i]==s[1]) b++;
            else
            {
                cout<<min(a,b)<<endl;
                a=b=0;
            }
        }
        cout<<min(a,b)<<endl;
    }
    return 0;
}
