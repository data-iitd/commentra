#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int N, K;
    cin >> N >> K;
    int lst[N];
    for ( int i = 0 ; i < N ; i++ ) {
        cin >> lst[i];
    }
    int lst_p[N];
    int lst_m[N];
    int p = 0, m = 0, x = 0, y = N - 1, lastx = N - 1, lasty = N - 1;
    for ( int i = 0 ; i < N ; i++ ) {
        if ( lst[i] == 0 ) {
            K--;
        }
        if ( lst[i] > 0 ) {
            lst_p[p++] = lst[i];
        }
        else if ( lst[i] < 0 ) {
            lst_m[y--] = lst[i];
        }
    }
    int check ( int k ) {
        int ans = 1000000000;
        for ( int j = 0 ; j <= k ; j++ ) {
            if ( j > lastx || k - j > lasty ) {
                continue;
            }
            if ( j == 0 ) {
                p = 0;
            }
            else {
                p = lst_p[j - 1];
            }
            if ( k - j == 0 ) {
                m = 0;
            }
            else {
                m = lst_m[lasty - ( k - j )];
            }
            ans = min ( ans , 2 * p + abs ( m ) , p + 2 * abs ( m ) );
        }
        return ans;
    }
    cout << check ( K ) << endl;
    return 0;
}

