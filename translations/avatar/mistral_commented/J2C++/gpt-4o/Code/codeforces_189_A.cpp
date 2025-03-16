#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays
#include <algorithm> // Including the algorithm library for max function

using namespace std; // Using the standard namespace

int main() { // Starting the main function
    int n; // Variable to store the number of elements in the array
    cin >> n; // Reading the number of elements from the console
    const int maxn = 4010; // Defining the maximum size of the dynamic programming array

    // Reading the three integers representing the array elements
    int a, b, c;
    cin >> a >> b >> c;

    // Defining a vector to store the array elements
    vector<int> arr = { a, b, c };

    vector<int> dp(maxn, INT_MIN); // Creating a dynamic programming array of size maxn initialized to minimum values

    dp[0] = 0; // Setting the first element to 0

    // Filling the dynamic programming array using two nested loops
    for (int i = 0; i < 3; i++) { // Looping through the array elements
        for (int j = arr[i]; j < dp.size(); j++) { // Looping through the dynamic programming array
            dp[j] = max(dp[j], dp[j - arr[i]] + 1); // Updating the maximum length ending at j
        }
    }

    // Printing the result, which is the maximum length ending at the nth index
    cout << dp[n] << endl;

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
