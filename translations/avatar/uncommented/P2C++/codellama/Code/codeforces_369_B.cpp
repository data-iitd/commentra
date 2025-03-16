#include <iostream>
using namespace std;
int get_nums ( int num , int t ) {
    int ans[num];
    for ( int i = 0 ; i < num ; i++ ) {
        if ( i < t % num ) {
            ans[i] = t / num + 1;
        } else {
            ans[i] = t / num;
        }
    }
    return ans[num - 1];
}
int main () {
    int n , k , l , r , sa , sk;
    cin >> n >> k >> l >> r >> sa >> sk;
    int ans[n];
    for ( int i = 0 ; i < k ; i++ ) {
        ans[i] = get_nums ( k , sk );
    }
    for ( int i = k ; i < n ; i++ ) {
        ans[i] = get_nums ( n - k , sa - sk );
    }
    for ( int i = 0 ; i < n ; i++ ) {
        cout << ans[i] << " ";
    }
    return 0;
}
