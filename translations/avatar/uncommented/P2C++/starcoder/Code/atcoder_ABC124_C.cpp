#include <bits/stdc++.h>
using namespace std;
int main ( ) {
	string s;
	cin >> s;
	int even = 0, odd = 0;
	for ( int i = 0 ; i < s.size ( ) ; i += 2 ) {
		if ( s [ i ] == '0' )
			even++;
		else
			odd++;
	}
	cout << min ( s.size ( ) - ( even + odd ), s.size ( ) - ( even + odd ) ) << endl;
	return 0;
}
