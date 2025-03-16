

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Create a stringstream to read input from the standard input stream
    stringstream ss ; 
    ss << endl ; 
    string line ; 
    getline ( cin, line ) ; 
    ss << line ; 
    string str [ 2 ] ; 
    ss >> str [ 0 ] >> str [ 1 ] ; 
    string u ; 
    getline ( cin, u ) ; 
    int a, b ; 
    ss.clear ( ) ; 
    ss.str ( u ) ; 
    ss >> a >> b ; 
    cout << ( u.compare ( str [ 0 ] ) == 0? ( a - 1 ) + " " + b : a + " " + ( b - 1 ) ) << endl ; 
    return 0 ; 
}

