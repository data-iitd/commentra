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
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        priority_queue<int> pq;
        int sum=0;
        for(int i=0;i<k;i++)
        {
            pq.push(a[i]);
            sum+=a[i];
        }
        int min=pq.top();
        int max=pq.top();
        for(int i=k;i<n;i++)
        {
            if(a[i]<min)
            {
                sum+=a[i];
                pq.pop();
                pq.push(a[i]);
                min=pq.top();
            }
            else if(a[i]>max)
            {
                sum-=max;
                pq.pop();
                pq.push(a[i]);
                max=pq.top();
                sum+=max;
            }
        }
        cout<<min<<" "<<sum<<endl;
    }
    return 0;
}
