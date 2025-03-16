

#include <iostream> // Including the necessary header file for input/output operations
#include <vector> // Including the necessary header file for dynamic arrays

using namespace std ; // Using the standard namespace for input/output operations

int main ( ) { // Defining the main function as the entry point of the program
    int n ; // Declaring an integer variable to store the number of test cases
    cin >> n ; // Reading the number of test cases from the input

    vector < int > FfriendPerDay ( 367, 0 ) ; // Initializing a dynamic array of size 367 to store the number of friends of type F for each day
    vector < int > MfriendPerDay ( 367, 0 ) ; // Initializing a dynamic array of size 367 to store the number of friends of type M for each day
    int answer = 0 ; // Initializing an integer variable to store the maximum difference between the number of friends of type F and M for any day

    for ( int i = 0 ; i < n ; i ++ ) { // Iterating through each test case
        char c ; // Declaring a character variable to store the gender of the friend
        int a, b ; // Declaring two integer variables to store the starting and ending days of the range
        cin >> c >> a >> b ; // Reading the gender and the range of days from the input

        for ( int j = a ; j <= b ; j ++ ) { // Iterating through each day in the range
            if ( c == 'M' ) MfriendPerDay [ j ] ++ ; // Incrementing the counter in the MfriendPerDay array for the day if the friend is of type M
            else FfriendPerDay [ j ] ++ ; // Incrementing the counter in the FfriendPerDay array for the day if the friend is of type F

            if ( MfriendPerDay [ j ] < FfriendPerDay [ j ] ) { // Checking if the number of friends of type M is less than the number of friends of type F for the current day
                if ( MfriendPerDay [ j ] > answer ) answer = MfriendPerDay [ j ] ; // Updating the value of answer if the current difference is greater than the previous maximum difference
            } else { // Repeating the same check for the number of friends of type F
                if ( FfriendPerDay [ j ] > answer ) answer = FfriendPerDay [ j ] ;
            }
        }
    }

    cout << answer * 2 << endl ; // Printing the answer, which is twice the maximum difference between the number of friends of type F and M for any day.

    return 0 ; // Returning 0 to indicate successful execution of the program
}

