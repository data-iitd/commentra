
#include <iostream>
#include <string>
using namespace std;

void cout ( string str ) {
cout << str << endl ;
} ;

int main ( ) {
string a = "", b = "", str ;
int n ;
cin >> n ;
cin.ignore ( ) ;
getline ( cin, str ) ;
for ( int i = 0 ; i < n / 2 ; i ++ ) {
a = a + str [ i ] ;
}
if ( str. compare ( a + a ) == 0 ) cout ( "Yes" ) ;
else cout ( "No" ) ;
return 0 ;
} ;

