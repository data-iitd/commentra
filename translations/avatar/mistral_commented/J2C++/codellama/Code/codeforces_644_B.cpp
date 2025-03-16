
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <set>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <climits>
#include <array>

using namespace std;

int main ( ) {
    int n, b;
    long int t, d;
    long int ans[100000];
    queue < long int > q;

    cin >> n >> b;

    for ( int i = 0 ; i < n ; i ++ ) {
        cin >> t >> d;

        while ( ! q.empty ( ) && q.front ( ) <= t ) {
            q.pop ( );
        }

        if ( q.size ( ) <= b ) {
            ans[i] = ( q.empty ( ) ? t : q.back ( ) ) + d;
            q.push ( ans[i] );
        } else {
            ans[i] = - 1;
        }
    }

    for ( int i = 0 ; i < n ; ++ i ) {
        cout << ans[i] << " ";
    }

    return 0;
}

