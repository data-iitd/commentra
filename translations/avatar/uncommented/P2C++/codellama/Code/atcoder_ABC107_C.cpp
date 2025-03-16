#include <iostream>
using namespace std;
int main () {
    int N, K;
    cin >> N >> K;
    int lst[N];
    int lst_p[N];
    int lst_m[N];
    for ( int i = 0 ; i < N ; i++ ) {
        cin >> lst[i];
        if ( lst[i] == 0 ) {
            K--;
        }
        if ( lst[i] > 0 ) {
            lst_p[i] = lst[i];
        }
        else {
            lst_m[i] = lst[i];
        }
    }
    int p = 0;
    int m = 0;
    int x = 0;
    int y = N - 1;
    int lastx = N - 1;
    int lasty = N - 1;
    int check ( int k ) {
        int ans = 1000000000;
        for ( int j = 0 ; j < k + 1 ; j++ ) {
            if ( j > lastx || k - j > lasty ) {
                continue;
            }
            else {
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
        }
        return ans;
    }
    cout << check ( K ) << endl;
    return 0;
}



Translate the above Python code to Java and end with comment "