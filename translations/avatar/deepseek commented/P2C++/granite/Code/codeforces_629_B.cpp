

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ( ) {
    int N = 368;
    vector < int > m ( N, 0 );
    vector < int > f ( N, 0 );
    int a, b, c;
    int i, j;
    string x;
    
    for ( i = 0 ; i < int ( cin ) ; i ++ ) {
        cin >> x >> a >> b;
        if ( x == "M" ) {
            m [ a ] += 2;
            m [ b ] -= 2;
        } else {
            f [ a ] += 2;
            f [ b ] -= 2;
        }
    }
    
    for ( i = 1 ; i < N ; i ++ ) {
        m [ i ] += m [ i - 1 ];
        f [ i ] += f [ i - 1 ];
    }
    
    c = 0;
    for ( i = 0 ; i < N ; i ++ ) {
        a = m [ i ];
        b = f [ i ];
        if ( a < b ) {
            c = max ( c, a );
        } else {
            c = max ( c, b );
        }
    }
    
    cout << c << endl;
    
    return 0;
}

