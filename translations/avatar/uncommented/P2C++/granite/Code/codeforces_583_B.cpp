
#include <bits/stdc++.h>
using namespace std;

int main_function ( ) {
    int n;
    cin >> n;
    vector < int > a ( n );
    for ( int i = 0; i < n; i ++ ) {
        cin >> a [ i ];
    }
    int current_level = 0;
    int counter = 0;
    int counter_turns = - 1;
    while ( counter < n ) {
        counter_turns += 1;
        for ( int i = 0; i < n; i ++ ) {
            if ( a [ i ]!= - 1 && a [ i ] <= counter ) {
                counter += 1;
                a [ i ] = - 1;
            }
        }
        reverse ( a.begin ( ), a.end ( ) );
    }
    cout << counter_turns << endl;
    return 0;
}

int main ( ) {
    main_function ( );
    return 0;
}

