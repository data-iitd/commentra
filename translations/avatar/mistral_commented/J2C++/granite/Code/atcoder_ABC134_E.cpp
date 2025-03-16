
#include <bits/stdc++.h>  // Include the C++ standard library

using namespace std ;  // Using the standard namespace

int main ( ) {  // Main function to start the program
    ios_base::sync_with_stdio ( false ) ;  // Disabling synchronization between C and C++ I/O streams
    cin.tie ( NULL ) ;  // Setting the input stream to null

    int n ;  // Declaring the variable n to store the number of test cases
    cin >> n ;  // Reading the number of test cases from the console

    map < int, int > mp ;  // Creating an empty map to store the frequency of each number

    while ( n -- > 0 ) {  // Loop through each test case
        int num ;  // Declaring the variable num to store the current number
        cin >> num ;  // Reading the number from the console

        if ( mp.lower_bound ( num ) == mp.begin ( ) ) {  // If the number is not present in the map
            int val = mp [ num ] ;  // Get the initial value of the number from the map or set it to 0 if not present
            mp [ num ] = ++ val ;  // Increment the value of the number in the map
        } else {  // If the number is already present in the map
            auto it = mp.lower_bound ( num ) ;  // Get the iterator to the previous number in the map
            it -- ;  // Move the iterator to the previous number in the map

            int val = it -> second ;  // Get the value (frequency) of the previous number from the map

            if ( val == 1 ) {  // If the frequency of the previous number is 1
                mp.erase ( it -> first ) ;  // Remove the previous number from the map
            } else {  // If the frequency of the previous number is greater than 1
                mp [ it -> first ] = -- val ;  // Decrement the frequency of the previous number in the map
            }

            int val = mp [ num ] ;  // Get the initial value of the current number from the map or set it to 0 if not present
            mp [ num ] = ++ val ;  // Increment the value of the current number in the map
        }
    }

    int ans = 0 ;  // Initializing the answer variable to 0

    for ( auto it : mp ) {  // Iterating through each element in the map
        int val = it. second ;  // Getting the value (frequency) of the current number from the map
        ans += val ;  // Adding the frequency of the current number to the answer
    }

    cout << ans << endl ;  // Printing the answer to the console

    return 0 ;  // Returning 0 to indicate successful execution of the program
}

