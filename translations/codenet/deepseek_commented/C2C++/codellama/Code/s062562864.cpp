#include<iostream>  // Include the standard input/output library
using namespace std;  // Use the standard namespace
int main(){       // Define the main function

    // Declare integer variables to store input values and intermediate results
    int a, b, c, d, i, j;

    // Read four integers from the user
    cin >> a >> b >> c >> d;

    // Perform multiplication operations and store the results in i and j
    i = a * b;
    j = c * d;

    // Use an if-else statement to compare the results and print the larger one
    if (i > j) {
        cout << i << endl;
    } else {
        cout << j << endl;
    }

    // Return 0 to indicate successful execution
    return 0;
}

