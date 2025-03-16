
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>

using namespace std ;

int main ( ) {
    int n ;                                                                                 // Declaring variables
    double sum_before = 0 , sum = 0 ;
    int non_int = 0 ;
    vector < double > arr ;

    // Reading the number of test cases
    cin >> n ;

    // Reading the elements of the array
    for ( int i = 0 ; i < 2 * n ; i ++ ) {
        double num ;
        cin >> num ;
        sum_before += num ;                                                                 // Adding the current number to the sum_before variable
        if ( num != floor ( num ) ) non_int ++ ;                                            // Incrementing the non_int variable if the current number is not an integer
        sum += floor ( num ) ;                                                              // Adding the floor value of the current number to the sum variable
        arr.push_back ( num ) ;                                                             // Assigning the current number to the corresponding index of the array
    }

    // Calculating the maximum and minimum sums
    double max_sum = min ( n , non_int ) + sum ;
    double min_sum = max ( 0 , non_int - n ) + sum ;

    // Calculating the answer based on the given conditions
    double ans ;
    if ( min_sum > sum_before ) ans = ( min_sum - sum_before ) ;
    else if ( max_sum < sum_before ) ans = ( sum_before - max_sum ) ;
    else {
        double x = sum_before - floor ( sum_before ) ;
        ans = min ( 1 - x , x ) ;
    }

    // Printing the answer
    cout << fixed << setprecision ( 3 ) << ans << endl ;

    return 0 ;
}

