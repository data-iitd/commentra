#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using dynamic arrays
#include <algorithm> // Including the algorithm library for using max function

using namespace std; // Using the standard namespace

int main() { // Starting point of the program
    int n; // Variable to store the number of elements in the array
    cin >> n; // Reading the number of elements from the standard input
    vector<int> a(n); // Creating a vector of integers of size n

    for (int i = 0; i < n; i++) { // Iterating through the vector to read its elements from the standard input
        cin >> a[i];
    }

    string s; // Variable to store the string
    cin >> s; // Reading the string from the standard input
    long long sum = 0; // Initializing the sum variable to zero

    for (int i = 0; i < s.length(); i++) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'B' characters
        char ch = s[i];
        if (ch == 'B') sum += a[i];
    }

    long long ans = sum; // Initializing the answer variable with the sum calculated above
    long long sum1 = sum; // Initializing a temporary sum variable with the sum calculated above

    for (int i = 0; i < s.length(); i++) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
        if (s[i] == 'A') sum1 += a[i];
        else sum1 -= a[i];
        ans = max(ans, sum1); // Updating the maximum sum found
    }

    sum1 = sum; // Resetting the temporary sum variable with the sum calculated at the beginning

    for (int i = s.length() - 1; i >= 0; i--) { // Iterating through the string in reverse order
        if (s[i] == 'A') sum1 += a[i];
        else sum1 -= a[i];
        ans = max(ans, sum1); // Updating the maximum sum found
    }

    cout << ans << endl; // Printing the maximum sum found
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
