#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main ( ) {
	string a;
	cin >> a;
	if ( a.find ( "1" ) == string::npos ) {
		cout << 0 << endl;
	} else {
		vector<string> b;
		string c = "";
		for ( int i = 0; i < a.size ( ); i++ ) {
			if ( a[i] == '1' ) {
				b.push_back ( c );
				c = "";
			} else {
				c += a[i];
			}
		}
		b.push_back ( c );
		int ans = 1;
		for ( int i = 0; i < b.size ( ); i++ ) {
			ans *= ( b[i].size ( ) + 1 );
		}
		cout << ans << endl;
	}
	return 0;
}
