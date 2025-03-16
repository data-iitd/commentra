
#include <bits/stdc++.h>
using namespace std;
vector<long long> l;
long long limit = 10000000000;
void gen ( long long number, long long four, long long seven ) {
    if ( number > limit ) {
        return;
    }
    if ( number > 0 && four == seven ) {
        l.push_back ( number );
    }
    gen ( number * 10 + 4, four + 1, seven );
    gen ( number * 10 + 7, four, seven + 1 );
}
int main ( ) {
    gen ( 0, 0, 0 );
    sort ( l.begin ( ), l.end ( ) );
    long long n;
    cin >> n;
    long long ans = 0;
    for ( auto val : l ) {
        if ( val >= n ) {
            ans = val;
            break;
        }
    }
    cout << ans << endl;
}
