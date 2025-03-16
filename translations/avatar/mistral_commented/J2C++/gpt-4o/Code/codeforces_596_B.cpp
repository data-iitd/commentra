#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Create a variable `n` to store the number of integers
    int n;
    // Read the first integer `n` from the standard input stream
    cin >> n;

    // Create a vector `arr` of size `n`
    vector<long> arr(n);

    // Use a for loop to read `n` integers from the standard input stream and assign them to the corresponding elements of the vector `arr`
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize the variable `answer` with the absolute value of the first element of the vector `arr`
    long answer = abs(arr[0]);

    // Use a for loop to iterate over the remaining elements of the vector `arr` and calculate the absolute difference between each element and the previous one, adding the result to the variable `answer`
    for (int i = 1; i < n; i++) {
        answer += abs(arr[i] - arr[i - 1]);
    }

    // Print the value of the variable `answer` to the standard output stream
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
