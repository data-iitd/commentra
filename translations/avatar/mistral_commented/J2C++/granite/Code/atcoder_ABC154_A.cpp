
######
// Importing necessary C++ libraries
######
#include <bits/stdc++.h>

######
// Main method is the entry point of the C++ application
######
using namespace std;

int main() {

    // Creating a BufferedReader object to read input from the console
    BufferedReader in = new BufferedReader ( new InputStreamReader ( System.in ) ) ;

    // Reading the first line of input as an array of strings
    String [ ] str = in.readLine ( ).split ( " " ) ;

    // Creating a StringTokenizer object to read the second line of input as separate tokens
    StringTokenizer st = new StringTokenizer ( in.readLine ( ) ) ;

    // Reading the first two integers as input
    int a = Integer.parseInt ( st.nextToken ( ) ) ;
    int b = Integer.parseInt ( st.nextToken ( ) ) ;

    // Reading the third line of input as a string
    String u = in.readLine ( ) ;

    // Checking if the first string from the first line matches with the given string 'u'
    if ( u.equals ( str [ 0 ] ) ) {

        // If the condition is true, then print the result as (a-1) and b
        cout << ( a - 1 ) << " " << b << endl ;

    } else {

        // If the condition is false, then print the result as a and (b-1)
        cout << a << " " << ( b - 1 ) << endl ;
    }

    // Closing the BufferedReader object to release the system resources
    in.close ( ) ;

    // End of C++ code
    return 0;
}
