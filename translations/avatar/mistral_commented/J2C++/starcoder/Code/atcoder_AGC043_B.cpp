
#include <bits/stdc++.h>
using namespace std;

// Declaring a private method to calculate the XOR operation on a given string with a specific character
int cal ( string s, char c ) {
    int n = s.length() ;  // Getting the length of the given string
    int m = n - 1 ;        // Initializing a variable'm' to keep track of the index of the previous character
    int ans = 0 ;          // Initializing a variable 'ans' to store the result of XOR operation
    
    for ( int i = 0 ; i < n ; i ++ ) {  // Looping through each character in the given string
        if ( s[i] == c && (m & i) == i ) { // Checking if the current character is the given character and the difference between its index and the index of the previous character is a power of 2
            ans ^= 1 ;            // If yes, performing XOR operation on 'ans'
        }
    }
    
    return ans ;             // Returning the result of XOR operation
}

// Declaring a private method to read input and process it
void solve ( ) {
    int n = sc.nextInt() ;  // Reading the number of test cases
    
    for ( int testCase = 1 ; testCase <= n ; testCase++ ) {  // Looping through each test case
        int num = sc.nextInt() ; // Reading the length of the given string
        string s = sc.next() ;    // Reading the given string
        
        stringstream sb ; // Creating a stringstream object to store the differences between adjacent characters
        
        for ( int i = 1 ; i < num ; i ++ ) { // Looping through each character except the first one in the given string
            sb << abs(s[i] - s[i - 1]) ; // Appending the absolute difference between adjacent characters to the stringstream object
        }
        
        if ( num == 2 ) { // Checking if the given string has only two characters
            out << sb.str()[0] << endl ; // If yes, printing the first character of the string
            continue ;                 // And moving to the next test case
        }
        
        s = sb.str() ; // Converting the stringstream object to a string object
        
        if ( s.find("1")!= string::npos ) { // Checking if the given string contains the character '1'
            out << cal(s,'1') << endl ; // If yes, printing the result of XOR operation on the given string with character '1'
        } else {
            out << cal(s,'2') * 2 << endl ; // If no, performing XOR operation on the given string with character '2' and multiplying the result by 2
        }
    }
}

// Declaring static variables for input/output operations
static ostream * out ;
static istream * in ;
static MyScanner * sc ;

// Declaring a static class to read input
class MyScanner {
public:
    MyScanner ( ) {
        in = &cin ;
        sc = new istream ( ) ;
    }
    
    MyScanner ( istream & stream ) {
        in = &stream ;
        sc = new istream ( ) ;
    }
    
    string next ( ) {
        return (*sc) >> ws, next_token ;
    }
    
    int nextInt ( ) {
        return stoi ( next() ) ;
    }
    
    long long nextLong ( ) {
        return stoll ( next() ) ;
    }
    
    double nextDouble ( ) {
        return stod ( next() ) ;
    }
} ;

// Declaring the main method to start the program
int main ( ) {
    out = &cout ;
    sc = new MyScanner ( ) ;
    solve ( ) ;
    return 0 ;
}

I hope these comments will help you understand the logic of the code better. Let me know if you have any questions!

