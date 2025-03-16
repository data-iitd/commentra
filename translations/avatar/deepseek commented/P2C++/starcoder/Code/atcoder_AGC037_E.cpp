
#include <bits/stdc++.h>
using namespace std;
int main ( ) {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    bool aaaa = false;
    if ( K >= 15 ) {
        aaaa = true;
    } else if ( 2 ** K >= N ) {
        aaaa = true;
    }
    if ( aaaa ) {
        cout << min ( S ) * N << endl;
        return 0;
    }
    string U = S + S.substr ( 0, N - 1 );
    char c = min ( S );
    int p = U.find ( c );
    int minindex = p;
    p += 1;
    while ( p <= N ) {
        if ( U [ p ] == c ) {
            if ( check_normal_dict ( U, minindex, p ) ) {
                minindex = p;
            }
        }
        p += 1;
    }
    string ans = U.substr ( minindex, N );
    if ( K == 1 ) {
        cout << ans << endl;
    } else {
        int count = 0;
        for ( int i = 0 ; i < N ; i++ ) {
            if ( ans [ i ] == ans [ 0 ] ) {
                count++;
            } else {
                break;
            }
        }
        if ( count * ( 2 ** ( K - 1 ) ) >= N ) {
            cout << ans [ 0 ] * N << endl;
        } else {
            ans = ans.substr ( 0, count * ( ( 2 ** ( K - 1 ) ) - 1 ) ) + ans;
            cout << ans.substr ( 0, N ) << endl;
        }
    }
    return 0;
}
bool check_normal_dict ( string u, int pointer1, int pointer2 ) {
    for ( int i = 0 ; i < N ; i++ ) {
        if ( u [ pointer1 + i ] > u [ pointer2 + i ] ) {
            return true;
        } else if ( u [ pointer1 + i ] < u [ pointer2 + i ] ) {
            return false;
        }
    }
    return false;
}

