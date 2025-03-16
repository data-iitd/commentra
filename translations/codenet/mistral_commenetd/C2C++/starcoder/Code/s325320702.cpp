#include<bits/stdc++.h>

using namespace std;

int main(void){
    // Main function

    ll l,r,d;
    ll ans=0;

    cin>>l;
    cin>>r;
    cin>>d;

    rep(i,l,r+1){
        if(i%d==0) ans++;
    }

    cout<<ans<<endl;

    return 0;
}

