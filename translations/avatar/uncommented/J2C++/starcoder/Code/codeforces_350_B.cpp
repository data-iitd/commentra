#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1],b[n+1],num[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        num[b[i]]++;
    string ss="";
    int ans=0;
    bool st[n+1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            st[i]=true;
            string sss="";
            sss+=to_string(i);
            reverse(sss.begin(),sss.end());
            ss+=" "+sss;
            int s=1;
            while(!st[b[i]] && num[b[i]]==1 && b[i]!=0 && a[b[i]]!=1)
            {
                sss="";
                sss+=to_string(b[i]);
                reverse(sss.begin(),sss.end());
                ss+=" "+sss;
                st[b[i]]=true;
                s++;
                b[i]=b[b[i]];
            }
            if(s>ans)
            {
                ans=s;
                ss=ss.substr(1);
            }
        }
    }
    cout<<ans<<endl;
    cout<<ss<<endl;
    return 0;
}
