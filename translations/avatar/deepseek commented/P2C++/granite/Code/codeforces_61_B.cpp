
#include <bits/stdc++.h>
using namespace std;

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
bool valid ( int i, int j, int n, int m ) {
    if ( i < n && i >= 0 && j >= 0 && j < m ) return true;
    return false;
}

// Function to calculate the sum of an arithmetic series from i to n
int sumn ( int i, int n ) {
    return ( n - i ) * ( i + n ) / 2;
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
double sqfun ( double a, double b, double c ) {
    return ( - b + sqrt ( b * b - 4 * a * c ) ) / 2 * a;
}

// Function to read a single or multiple integer values from input
tuple<int> value () { return tuple<int>([&] () { int x; cin >> x; return x; }()); }

// Function to read a single or multiple integer values from standard input
tuple<int> values () { return tuple<int>([&] () { int x; cin >> x; return x; }()); }

// Function to read a list of integers from input
vector<int> inlst () { return vector<int>([&] () { int x; cin >> x; return x; }()); }

// Function to read a list of integers from standard input
vector<int> inlsts () { return vector<int>([&] () { int x; cin >> x; return x; }()); }

// Function to read a single integer from input
int inp () { return ([&] () { int x; cin >> x; return x; }()); }

// Function to read a single integer from standard input
int inps () { return ([&] () { int x; cin >> x; return x; }()); }

// Function to read a string from input
string instr () { return ([&] () { string x; cin >> x; return x; }()); }

// Function to split a string into a list of words
vector<string> stlst () { return vector<string>([&] () { string x; cin >> x; return x; }()); }

// Function to sanitize a string by converting it to lowercase and removing certain characters
string f ( string s ) {
    string r = "";
    for ( char i : s ) {
        if ( i!= '-' && i!= ';' && i!= '_' ) r += tolower ( i );
    }
    return r;
}

// Main logic of the program
void solve () {
    vector<string> l;
    for ( int i = 0; i < 3; i++ ) {
        l.push_back ( f ( instr ( ) ) );
    }
    vector<string> t;
    for ( int i = 0; i < 3; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            if ( i!= j ) {
                for ( int k = 0; k < 3; k++ ) {
                    if ( i!= k && j!= k ) {
                        string s = "";
                        s += l[i];
                        s += l[j];
                        s += l[k];
                        t.push_back ( s );
                    }
                }
            }
        }
    }
    for ( int i = 0; i < inp ( ); i++ ) {
        if ( f ( instr ( ) ) == t[i] ) cout << "ACC" << endl;
        else cout << "WA" << endl;
    }
}

int main () {
    solve ( );
    return 0;
}

