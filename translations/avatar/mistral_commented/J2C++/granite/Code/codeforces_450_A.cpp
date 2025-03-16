

#include <iostream> // Including the standard input/output stream objects iostream and endl
#include <queue> // Including the queue container from the standard template library

using namespace std ; // Using the standard namespace

int main ( ) { // Starting the main method
    int n, m ; // Declaring two integer variables n and m
    cin >> n >> m ; // Reading the first integer n and the second integer m from the standard input
    queue < int > q1 ; // Creating an empty queue q1 of type int
    queue < int > q2 ; // Creating an empty queue q2 of type int

    for ( int i = 1 ; i <= n ; i ++ ) { // Iterating through the input values from 1 to n
        int x ; // Declaring an integer variable x
        cin >> x ; // Reading the next integer value from the standard input
        q1.push ( x ) ; // Adding the next integer value to the queue q1
        q2.push ( i ) ; // Adding the current index value to the queue q2
    }

    int ans = 0 ; // Initializing the answer variable to 0
    while (! q1.empty ( ) ) { // Starting the while loop to process the queues until both are empty
        if ( q1.front ( ) <= m ) { // Checking if the next value in q1 is less than or equal to m
            q1.pop ( ) ; // Removing the next value from q1
            ans = q2.front ( ) ; // Removing the next value from q2 and assigning it to the answer variable
            q2.pop ( ) ; // Removing the corresponding index value from q2
        } else if ( q1.front ( ) > m ) { // Checking if the next value in q1 is greater than m
            int x = q1.front ( ) ; // Storing the next value from q1 in an integer variable x
            q1.pop ( ) ; // Removing the next value from q1
            int val = x - m ; // Calculating the new value by subtracting m from the next value
            q1.push ( val ) ; // Adding the new value back to the queue q1
            int val2 = q2.front ( ) ; // Storing the next value from q2 in an integer variable val2
            q2.pop ( ) ; // Removing the next value from q2
            q2.push ( val2 ) ; // Adding the index value back to the queue q2
        }
    }

    cout << ans << endl ; // Printing the final answer
    return 0 ; // Returning 0 to indicate successful program execution
}

These comments should provide a clear understanding of the code logic for each block.