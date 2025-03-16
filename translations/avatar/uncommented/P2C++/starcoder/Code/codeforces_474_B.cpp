#include <iostream>
#include <vector>
using namespace std;
int main ( ) {
    vector<int> L;
    int r = 1;
    string s;
    cin >> s;
    for ( int k = 0; k < s.size ( ); k++ ) {
        L.insert ( L.end ( ), r, int ( s[k] ) );
        r += 1;
    }
    cin >> s;
    for ( int j = 0; j < s.size ( ); j++ ) {
        cout << L[int(s[j])-1] << endl;
    }
    return 0;
}
