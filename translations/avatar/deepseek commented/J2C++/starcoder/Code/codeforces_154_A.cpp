
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Reading input from standard input
    cin.sync_with_stdio(0);
    cin.tie(0);
    char arr [ ] ;
    cin >> arr ; // Read a line and convert it to a character array
    int N = strlen ( arr ) ; // Store the length of the character array
    
    // Initialize a HashSet to store unique strings and read the number of test cases
    unordered_set < string > set ; 
    int K ;
    cin >> K ; 
    
    // Initialize the result variable to store the final count
    int res = 0 ; 
    
    // Loop to process each test case
    for ( int k = 0 ; k < K ; k ++ ) { 
        string input ;
        cin >> input ; // Read the input string for the current test case
        int a = 0 ; // Counter for the first character of the input
        int b = 0 ; // Counter for the second character of the input
        
        // Iterate over the characters of the input array
        for ( int i = 0 ; i < N ; i ++ ) { 
            if ( arr [ i ] == input [ 0 ] ) // If the character matches the first character of the input
                a ++ ; 
            else if ( arr [ i ] == input [ 1 ] ) // If the character matches the second character of the input
                b ++ ; 
            else { // If the character does not match either of the input characters
                res += min ( a, b ) ; // Add the minimum of a and b to the result
                a = b = 0 ; // Reset the counters
            } 
        } 
        res += min ( a, b ) ; // Add the minimum of a and b to the result after the loop
    } 
    
    // Print the final result
    cout << res << endl ; 
}

