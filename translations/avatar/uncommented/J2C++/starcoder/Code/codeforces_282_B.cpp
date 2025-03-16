#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    int s1=0,s2=0;
    int i,j=0,flag=0,dif=0;
    for(i=0;i<n;i++)
    {
        int x=a[i],y=b[i];
        int temp1=s1+x,temp2=s2+y;
        if(abs(temp1-s2)<=500)
        {
            s1+=x;
            j++;
            continue;
        }
        if(abs(temp2-s1)<=500)
        {
            s2+=y;
            j++;
            continue;
        }
        flag=1;
        break;
    }
    if(flag==1)
    {
        cout<<-1<<endl;
    }
    else
    {
        string ans="";
        for(i=0;i<j;i++)
        {
            ans+=ch[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
