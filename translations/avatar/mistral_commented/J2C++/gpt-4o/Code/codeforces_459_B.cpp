#include <iostream> // Include header for input/output
#include <vector>   // Include header for using vectors
#include <algorithm> // Include header for sorting
#include <numeric>   // Include header for numeric operations

using namespace std;

int main() {
    int N; // Declare an integer N to store the number of elements
    cin >> N; // Read the number of elements from standard input
    vector<int> A(N); // Create a vector A of size N to store the elements

    // Use a for loop to read each element from standard input and store it in the vector A
    for (int n = 0; n < N; n++) {
        cin >> A[n];
    }

    // Sort the elements in the vector A in ascending order
    sort(A.begin(), A.end());

    // Initialize two variables, min and max, to store the minimum and maximum elements in the vector A, respectively
    int min = A[0];
    int max = A[N - 1];

    // Initialize counters for the occurrences of min and max
    long long mins = 0, maxs = 0;

    // Use a for-each loop to iterate through each element in the vector A and perform some checks
    for (int value : A) {
        if (value == min) { // If the current element is equal to the minimum element min, increment mins
            mins++;
        }
        if (value == max) { // If the current element is equal to the maximum element max, increment maxs
            maxs++;
        }
    }

    // Check if the minimum and maximum elements are the same
    if (min == max) {
        long long result = (max - min) + 1; // Calculate the difference between the minimum and maximum elements, plus 1
        result *= mins; // Multiply the result by the number of occurrences of the minimum element
        result -= mins * (mins - 1) / 2; // Subtract the number of combinations of pairs of minimum elements
        cout << result << endl; // Print the output
    } else {
        long long result = (max - min); // Calculate the difference between the minimum and maximum elements
        result *= mins; // Multiply the result by the number of occurrences of the minimum element
        result *= maxs; // Multiply the result by the number of occurrences of the maximum element
        cout << result << endl; // Print the output
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
