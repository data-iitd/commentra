#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int arr[n];
    arr[0]=sc.nextInt();
    for(int i=1;i<n;i++)
    {
        int x=sc.nextInt();
        arr[i]=x+arr[i-1];
    }
    cin>>m;
    int q[m];
    for(int i=0;i<m;i++)
    {
        q[i]=sc.nextInt();
    }
    for(int k=0;k<m;k++)
    {
        cout<<fun(arr,q[k],n,m)+1<<endl;
    }
    return 0;
}
static int fun(int arr[],int q,int n,int m)
{
    int res=0;
    int i=0,j=n;
    while(i<=j)
    {
        int md=i+(j-i)/2;
        if(arr[md]==q)
            return md;
        else if(arr[md]>q)
        {
            res=md;
            j=md-1;
        }
        else
            i=md+1;
    }
    return res;
}
