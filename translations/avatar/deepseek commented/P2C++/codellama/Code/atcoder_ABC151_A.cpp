
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool debug = false;
void log ( string text ) {
    if ( debug ) {
        cout << text << endl;
    }
}
// Function to parse input from either user input or a string
vector < string > parse_input ( string lines_as_string = "" ) {
    bool debug = false;
    vector < string > lines;
    if ( lines_as_string == "" ) {
        debug = false;
        lines.push_back ( "" );
        getline ( cin , lines [ 0 ] );
    } else {
        debug = true;
        lines = [ e for e in lines_as_string.split ( "\n" ) ] [ 1 : - 1 ];
    }
    string c = [ e for e in lines [ 0 ].split ( " " ) ] [ 0 ];
    return { c };
}
// Function to solve the problem by finding the next character in the alphabet
string solve ( string c ) {
    string a = "abcdefghijklmnopqrstuvwxyz";
    int i = find ( a.begin ( ) , a.end ( ) , c ) - a.begin ( );
    return a [ i + 1 ];
}
// Main function to orchestrate the execution of the program
int main ( ) {
    string result = solve ( parse_input ( ) [ 0 ] );
    if ( isinstance ( result , vector < string > ) ) {
        for ( string r : result ) {
            cout << r << endl;
        }
    } else {
        cout << result << endl;
    }
    return 0;
}



