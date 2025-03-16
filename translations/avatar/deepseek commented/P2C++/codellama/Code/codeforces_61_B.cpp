#include <bits/stdc++.h>
using namespace std;

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
bool valid ( int i , int j , int n , int m ) {
    if ( i < n && i >= 0 && j >= 0 && j < m ) return true;
    return false;
}

// Function to calculate the sum of an arithmetic series from i to n
int sumn ( int i , int n ) {
    return ( n - i ) * ( i + n ) / 2;
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
double sqfun ( double a , double b , double c ) {
    return ( - b + sqrt ( b * b - 4 * a * c ) ) / 2 * a;
}

// Function to read a single or multiple integer values from input
vector < int > value ( ) {
    vector < int > v;
    string s;
    cin >> s;
    stringstream ss ( s );
    int i;
    while ( ss >> i ) v.push_back ( i );
    return v;
}

// Function to read a single or multiple integer values from standard input
vector < int > values ( ) {
    vector < int > v;
    string s;
    getline ( cin , s );
    stringstream ss ( s );
    int i;
    while ( ss >> i ) v.push_back ( i );
    return v;
}

// Function to read a list of integers from input
vector < int > inlst ( ) {
    vector < int > v;
    string s;
    cin >> s;
    stringstream ss ( s );
    int i;
    while ( ss >> i ) v.push_back ( i );
    return v;
}

// Function to read a list of integers from standard input
vector < int > inlsts ( ) {
    vector < int > v;
    string s;
    getline ( cin , s );
    stringstream ss ( s );
    int i;
    while ( ss >> i ) v.push_back ( i );
    return v;
}

// Function to read a single integer from input
int inp ( ) {
    int i;
    cin >> i;
    return i;
}

// Function to read a single integer from standard input
int inps ( ) {
    int i;
    getline ( cin , i );
    return i;
}

// Function to read a string from input
string instr ( ) {
    string s;
    cin >> s;
    return s;
}

// Function to split a string into a list of words
vector < string > stlst ( ) {
    vector < string > v;
    string s;
    cin >> s;
    stringstream ss ( s );
    string i;
    while ( ss >> i ) v.push_back ( i );
    return v;
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
string f ( string s ) {
    string r = "";
    for ( int i = 0 ; i < s.size ( ) ; i++ ) {
        if ( s [ i ] != '-' && s [ i ] != ';' && s [ i ] != '_' ) r += s [ i ];
    }
    return r;
}

// Main logic of the program
void solve ( ) {
    vector < string > l;
    for ( int i = 0 ; i < 3 ; i++ ) {
        l.push_back ( f ( instr ( ) ) );
    }
    vector < string > t = permutations ( l , l.size ( ) );
    l.clear ( );
    for ( int i = 0 ; i < t.size ( ) ; i++ ) {
        l.push_back ( "".join ( t [ i ] ) );
    }
    for ( int i = 0 ; i < inp ( ) ; i++ ) {
        if ( f ( instr ( ) ) in l ) cout << "ACC" << endl;
        else cout << "WA" << endl;
    }
}

int main ( ) {
    solve ( );
    return 0;
}

