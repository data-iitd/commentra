
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std ;

int main ( ) {
    int t ; // Number of test cases
    cin >> t ; // Read the number of test cases

    string s [ ] ; // Array to store each line of input
    priority_queue < int > pqmax ; // Max Heap to store the maximum elements
    priority_queue < int > pqmin ; // Min Heap to store the minimum elements
    long sumMin = 0 , sumMax = 0 , sumb = 0 ; // Variables to store the sum of minimum and maximum elements and the sum of the current element
    int min = 0 ; // Variable to store the minimum element

    while ( t -- > 0 ) { // Loop through all the test cases
        cin >> s [ ] ; // Read each line of input

        if ( s [ 0 ].charAt ( 0 ) == '2' ) { // If the first character of the line is '2'
            long ans = min ; // Answer is the product of the minimum element and the size of the min heap
            ans *= pqmin.size ( ) ;
            ans -= sumMin ; // Subtract the sum of minimum elements before the current minimum
            long ans1 = min ; // Answer1 is the product of the minimum element and the size of the max heap
            ans1 = sumMax - ans1 ; // Subtract the sum of maximum elements before the current minimum
            cout << min + " " + ( ans + ans1 + sumb ) << endl ; // Print the answer
        } else { // Else the first character of the line is not '2'
            int in = stoi ( s [ 1 ] ) ; // Read the integer value from the input
            sumb += stol ( s [ 2 ] ) ; // Add the long value to the sum of the current element

            if ( in > min ) { // If the input is greater than the current minimum
                pqmax.push ( in ) ; // Add the input to the max heap
                sumMax += in ; // Add the input to the sum of maximum elements
            } else { // Else the input is smaller than the current minimum
                pqmin.push ( in ) ; // Add the input to the min heap
                sumMin += in ; // Add the input to the sum of minimum elements
            }

            if ( pqmin.size ( ) > pqmax.size ( ) ) { // If the size of min heap is greater than the size of max heap
                sumMax += pqmin.top ( ) ; // Add the minimum element to the sum of maximum elements
                sumMin -= pqmin.top ( ) ; // Subtract the minimum element from the sum of minimum elements
                pqmax.push ( pqmin.top ( ) ) ; // Add the polled element from min heap to max heap
                pqmin.pop ( ) ; // Pop the polled element from min heap
            } else if ( pqmin.size ( ) < pqmax.size ( ) ) { // Else if the size of min heap is smaller than the size of max heap
                sumMax -= pqmax.top ( ) ; // Subtract the maximum element from the sum of maximum elements
                sumMin += pqmax.top ( ) ; // Add the maximum element to the sum of minimum elements
                pqmin.push ( pqmax.top ( ) ) ; // Add the polled element from max heap to min heap
                pqmax.pop ( ) ; // Pop the polled element from max heap
            }

            min = pqmin.top ( ) ; // Update the minimum element
        }
    }

    return 0 ; // Return 0
}

