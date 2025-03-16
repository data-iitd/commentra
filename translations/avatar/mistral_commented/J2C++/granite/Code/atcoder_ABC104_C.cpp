
// Importing the required C++ utility library
#include <iostream>
#include <vector>
#include <algorithm>

// Main function declaration
int main ( ) {

    // Creating a vector of pairs to store the values of p and c for each test case
    std::vector < std::pair < int, int > > v ;

    // Declaring and initializing a variable D to store the number of test cases
    int D ;

    // Declaring and initializing a variable G to store the goal score
    int G ;

    // Reading the number of test cases D and the goal score G from the standard input
    std::cin >> D >> G ;

    // Looping through each test case i and reading the values of p[i] and c[i]
    for ( int i = 0 ; i < D ; i ++ ) {
        int p, c ;
        std::cin >> p >> c ;
        v.push_back ( std::make_pair ( p, c ) ) ;
    }

    // Declaring and initializing a variable min to a large value
    int min = 100000 ;

    // Looping through all possible combinations of bits using a binary number
    for ( int bit = 0 ; bit < ( 1 << D ) ; bit ++ ) {

        // Initializing variables score and solve_num to zero
        int score = 0 ;
        int solve_num = 0 ;

        // Looping through each test case i
        for ( int i = 0 ; i < D ; i ++ ) {

            // Checking if the current bit is set in the binary number
            if ( ( bit & ( 1 << i ) )!= 0 ) {

                // Adding the score for the current test case i to the total score
                score += 100 * ( i + 1 ) * v [ i ].first + v [ i ].second ;

                // Incrementing the number of test cases solved so far
                solve_num += v [ i ].first ;
            }
        }

        // Checking if the current combination of bits can form a valid solution
        if ( score < G ) {

            // Backtracking to find the minimum number of test cases to be solved
            for ( int i = D - 1 ; i >= 0 ; i -- ) {

                // If the current bit is not set in the binary number
                if ( ( bit & ( 1 << i ) ) == 0 ) {

                    // Looping through each test case j that can be added to the current solution
                    for ( int j = 0 ; j < v [ i ].first - 1 ; j ++ ) {

                        // Adding the score for the current test case i and the current test case j to the total score
                        score += 100 * ( i + 1 ) ;

                        // Incrementing the number of test cases solved so far
                        solve_num ++ ;

                        // Checking if the current combination of bits can form a valid solution
                        if ( score >= G ) {

                            // Breaking out of the inner loop as we have found a valid solution
                            break ;
                        }
                    }
                }

                // If we have found a valid solution, we can break out of the outer loop as well
                if ( score >= G ) {
                    break ;
                }
            }
        }

        // Updating the minimum number of test cases if the current combination of bits can form a valid solution with a smaller number of test cases
        if ( score >= G ) {
            min = std::min ( min, solve_num ) ;
        }
    }

    // Printing the minimum number of test cases required to form a valid solution
    std::cout << min << std::endl ;

    // Ending the program
    return 0 ;
}

