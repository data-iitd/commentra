#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, int q) {
        // Write your code here
        set<int> left;
        for(int i=0;i<n;i++) left.insert(i);
        int answer[n];
        for(int i=0;i<q;i++){
            int l=in.nextInt()-1;
            int r=in.nextInt()-1;
            int win=in.nextInt()-1;
            while(left.upper_bound(l)!=NULL && *left.upper_bound(l)<=r){
                int curr=*left.upper_bound(l);
                answer[curr]=win;
                left.erase(curr);
            }
            answer[win-1]=0;
            left.insert(win-1);
        }
        for(int i=0;i<n;i++) cout<<answer[i]<<" ";
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        Solution ob;
        ob.solve(n,q);
    }
    return 0;
}

