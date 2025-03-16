#include <iostream>  // Including necessary header for input and output
#include <vector>    // Including vector for dynamic array
#include <algorithm> // Including algorithm for sorting
#include <iomanip>   // Including iomanip for setting precision

using namespace std;

int main() {
    int num = 998244353;  // Initializing a variable 'num' with a value
    int n;                // Variable to store the number of test cases
    cin >> n;            // Reading the number of test cases from the input

    vector<int> ai;      // Creating a vector to store the first array elements
    vector<int> bi;      // Creating a vector to store the second array elements

    for (int i = 0; i < n; i++) {  // Iterating through the test cases
        int a, b;  // Variables to store the elements of the arrays
        cin >> a >> b;  // Reading the elements for both arrays
        ai.push_back(a);  // Adding the first array element to the vector
        bi.push_back(b);  // Adding the second array element to the vector
    }

    // Sorting the vectors in ascending order
    sort(ai.begin(), ai.end());
    sort(bi.begin(), bi.end());

    if (n % 2 == 1) {  // Checking if the number of test cases is odd
        cout << bi[bi.size() / 2] - ai[ai.size() / 2] + 1 << endl;  // Calculating and printing the answer for odd number of test cases
    } else {
        double b = (ai[ai.size() / 2] + ai[ai.size() / 2 - 1]) / 2.0;  // Calculating the average of the middle two elements of the first vector
        double c = (bi[bi.size() / 2] + bi[bi.size() / 2 - 1]) / 2.0;  // Calculating the average of the middle two elements of the second vector
        cout << static_cast<int>(2 * (c - b) + 1) << endl;  // Calculating and printing the answer for even number of test cases
    }

    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
