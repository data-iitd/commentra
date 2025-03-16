#include <iostream>  // Importing iostream for input and output
#include <vector>   // Importing vector for dynamic array
using namespace std;

int main() {
    // Creating a variable for reading input from the console
    int n, m;
    
    // Reading the first two integers from the input
    cin >> n >> m;

    // Creating a vector 'a' of size 'm'
    vector<int> a(m);

    // Checking if 'n' is divisible by 'm'
    if (n % m == 0) {
        // If 'n' is divisible by 'm', then 'n' can be divided evenly by 'm'
        // So, all elements of 'a' will be equal to the quotient of 'n' and 'm'
        for (int i = 0; i < a.size(); i++) {
            a[i] = n / m; // Assigning the quotient to each element of 'a'
        }
    } else {
        // If 'n' is not divisible by 'm', then 'n' can't be divided evenly by 'm'
        // So, we need to calculate the quotient 'sub' and the remainder 'test' of 'n' by 'm'
        int sub = n / m;

        // All elements of 'a' will be equal to 'sub', except for some elements at the end
        for (int i = 0; i < a.size(); i++) {
            a[i] = sub; // Assigning 'sub' to each element of 'a'
        }

        // Calculating the number of extra elements needed at the end of 'a'
        int test = n - (sub * m);

        // Adding '1' to each extra element of 'a'
        int count = 0;
        for (int i = 0; i < test; i++) {
            a[count] = a[count] + 1; // Incrementing the value of each extra element by '1'
            count++;

            // If we reach the end of 'a', then we reset the index to '0'
            if (count >= a.size()) count = 0;
        }
    }

    // Printing the elements of 'a' in reverse order
    for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i] << " ";
    }

    return 0;
}

// <END-OF-CODE>
