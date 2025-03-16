#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num = 998244353;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int> ai,bi;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        ai.push_back(a);
        bi.push_back(b);
    }
    sort(ai.begin(),ai.end());
    sort(bi.begin(),bi.end());
    if(n%2==1)
    {
        cout<<bi[bi.size()/2]-ai[ai.size()/2]+1<<endl;
    }
    else
    {
        double b = (ai[ai.size()/2]+ai[ai.size()/2-1]+0.0)/2;
        double c = (bi[bi.size()/2]+bi[bi.size()/2-1]+0.0)/2;
        cout<<(int)(2*(c-b)+1)<<endl;
    }
    return 0;
}
