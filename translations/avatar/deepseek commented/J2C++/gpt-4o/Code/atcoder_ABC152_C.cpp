#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solve() {
    // Create a variable to read input
    int N;
    cin >> N;

    // Initialize a vector to store the integers
    vector<int> arr(N);

    // Read N integers from the input and store them in the vector
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Initialize a sum variable to 0
    int sum = 0;

    // Create a priority queue to store the integers in ascending order
    priority_queue<int, vector<int>, greater<int>> q;

    // Iterate through the vector and add each element to the priority queue
    for (int i = 0; i < arr.size(); i++) {
        q.push(arr[i]);

        // Check if the current element is less than or equal to the smallest element in the priority queue
        if (arr[i] <= q.top()) {
            sum++;
        }
    }

    // Return the sum
    return sum;
}

int main() {
    cout << solve() << endl;
    return 0;
}

// <END-OF-CODE>
