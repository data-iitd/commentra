#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    int N;
    cin >> N;

    // Initialize a vector to hold the input values
    vector<int> a(N);

    // Populate the vector with input values
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Vectors to hold the counts of elements to the left and right of each element
    vector<int> leftl(N, 0);
    vector<int> rightl(N, 0);

    // Deque to help with calculating the left and right counts
    deque<int> que;

    // Calculate the right counts for each element
    int index = 0;
    while (index < N) {
        // While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while (!que.empty() && a[que.front()] > a[index]) {
            // Pop the index from the deque and calculate the right count
            int ind = que.front();
            que.pop_front();
            rightl[ind] = index - ind - 1;
        }
        // Push the current index onto the deque
        que.push_front(index++);
    }

    // For any remaining indices in the deque, calculate the right counts
    while (!que.empty()) {
        int ind = que.front();
        que.pop_front();
        rightl[ind] = N - ind - 1;
    }

    // Reset index to calculate left counts
    index = N - 1;

    // Calculate the left counts for each element
    while (index >= 0) {
        // While the deque is not empty and the current element is smaller than the element at the index at the front of the deque
        while (!que.empty() && a[que.front()] > a[index]) {
            // Pop the index from the deque and calculate the left count
            int ind = que.front();
            que.pop_front();
            leftl[ind] = ind - index - 1;
        }
        // Push the current index onto the deque
        que.push_front(index--);
    }

    // For any remaining indices in the deque, calculate the left counts
    while (!que.empty()) {
        int ind = que.front();
        que.pop_front();
        leftl[ind] = ind - index - 1;
    }

    // Calculate the final answer based on the left and right counts
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        // For each element, multiply its value by the number of valid subarrays it can form
        ans += (long long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }

    // Output the final result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
