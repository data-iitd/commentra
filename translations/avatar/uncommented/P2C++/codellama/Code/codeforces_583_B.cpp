#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main ( ) {
    int n;
    cin >> n;
    vector < int > a;
    for ( int i = 0; i < n; i++ ) {
        int temp;
        cin >> temp;
        a.push_back ( temp );
    }
    int current_level = 0;
    int counter = 0;
    int counter_turns = - 1;
    while ( counter < a.size ( ) ) {
        counter_turns += 1;
        for ( int i = 0; i < a.size ( ); i++ ) {
            if ( a [ i ] != - 1 && a [ i ] <= counter ) {
                counter += 1;
                a [ i ] = - 1;
            }
        }
        reverse ( a.begin ( ), a.end ( ) );
    }
    cout << counter_turns << endl;
    return 0;
}
