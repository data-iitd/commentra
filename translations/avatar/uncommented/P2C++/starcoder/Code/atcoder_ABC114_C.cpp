#include <iostream>
#include <string>
using namespace std;
int main ( ) {
    int N;
    cin >> N;
    int aaa ( int n ) {
        if ( n > N ) {
            return 0;
        }
        int ans = 1;
        if ( set < char > ( to_string ( n ) ) == { '7', '5', '3' } ) {
            ans = 1;
        }
        for ( char i : { '7', '5', '3' } ) {
            ans += aaa ( n + i );
        }
        return ans;
    }
    cout << aaa ( 0 ) << endl;
    return 0;
}
