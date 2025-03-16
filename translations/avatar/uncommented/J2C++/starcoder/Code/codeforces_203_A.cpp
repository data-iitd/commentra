#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,t,a,b,da,db;
    cin>>x>>t>>a>>b>>da>>db;
    bool ok = false;
    for(int i=0;i<t;i++){
        int first = a - (da*i);
        for(int j=0;j<t;j++){
            int second = b - (db*j);
            if(second + first == x || second == x || first == x || x == 0){
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
    return 0;
}
