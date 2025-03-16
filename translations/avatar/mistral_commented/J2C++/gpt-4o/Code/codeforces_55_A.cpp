#include <iostream>  // Including necessary header for input and output
#include <vector>   // Including necessary header for using vectors

using namespace std;  // Using the standard namespace

int main() {
    int n, i = 1, k = 0, p = 1;  // Declaring and initializing variables
    bool flag = true;  // Initializing the boolean variable 'flag' to true
    vector<int> a(1000, 0);  // Declaring and initializing a vector of size 1000 with all elements set to 0

    cin >> n;  // Reading the first integer from the standard input stream and assigning it to the variable 'n'

    while (k <= n) {  // Starting a while loop that runs as long as 'k' is less than or equal to 'n'
        i += k;  // Incrementing the variable 'i' by the value of 'k'

        if (i >= n) {  // Checking if the value of 'i' is greater than or equal to 'n'
            while (i >= n) i -= n;  // If yes, then decrement 'i' by 'n' until it becomes less than 'n'
        }

        ++a[i];  // Incrementing the value of the 'i'-th element of the vector 'a' by 1
        ++k;  // Incrementing the variable 'k' by 1
    }

    for (i = 0; i < n; ++i) {  // Starting a for loop that runs from 0 to 'n'-1
        if (a[i] == 0) {  // Checking if the 'i'-th element of the vector 'a' is equal to 0
            flag = false;  // If yes, then set the boolean variable 'flag' to false
            break;  // Exiting the for loop
        }
    }

    if (flag) cout << "YES" << endl;  // If the boolean variable 'flag' is still true after the for loop, then print "YES"
    else cout << "NO" << endl;  // Otherwise, print "NO"

    return 0;  // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
