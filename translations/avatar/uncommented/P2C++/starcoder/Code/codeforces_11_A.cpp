#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n,d,m,q,i;
    cin>>n>>d;
    int x[n];
    for(i=0;i<n;i++)
    {
        cin>>x[i];
    }
    m=0;
    for(i=0;i<n-1;i++)
    {
        q=int((x[i]-x[i+1])/d+1);
        m=m+q;
        x[i+1]=x[i+1]+q*d;
    }
    cout<<m<<endl;
    return 0;
}
