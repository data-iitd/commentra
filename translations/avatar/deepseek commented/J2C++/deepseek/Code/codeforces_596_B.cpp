#include <iostream>
#include <cmath> // Include the cmath library to use the abs function.
using namespace std;

int main() {
    int n;
    cin >> n; // Read the size of the array from the user.
    long long arr[n]; // Create an array to store the elements of the array.
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Read the elements of the array from the user.
    }
    long long answer = abs(arr[0]); // Initialize a variable to store the answer.
    for (int i = 1; i < n; i++) {
        answer += abs(arr[i] - arr[i - 1]); // Calculate the absolute difference between consecutive elements and add it to the answer.
    }
    cout << answer << endl; // Print the final answer.
    return 0;
}

