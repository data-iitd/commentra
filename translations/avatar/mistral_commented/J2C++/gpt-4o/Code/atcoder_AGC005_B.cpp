#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using dynamic arrays
#include <deque>    // Including the deque library for using double-ended queues

using namespace std;

int main() {
    int N; // Variable to store the number of elements in the array
    cin >> N; // Reading the number of elements from the console
    vector<int> a(N); // Creating a vector of size N to store the elements

    // Reading the elements of the array from the console
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<int> leftl(N, 0); // Vector to store the length of the left segment for each element
    vector<int> rightl(N, 0); // Vector to store the length of the right segment for each element
    deque<int> que; // Creating a deque to implement a double-ended queue
    int index = 0; // Initializing the index variable to traverse the array

    // Finding the length of the right segments for each element
    while (index < N) {
        while (!que.empty() && a[que.back()] > a[index]) { // Popping elements from the deque
            int ind = que.back(); // Storing the index of the popped element
            que.pop_back(); // Removing the last element from the deque
            rightl[ind] = index - ind - 1; // Calculating the length of the right segment
        }
        que.push_back(index++); // Pushing the current index into the deque
    }

    // Calculating the length of the right segment for the last elements
    while (!que.empty()) {
        int ind = que.back();
        que.pop_back();
        rightl[ind] = N - ind - 1;
    }

    index = N - 1; // Initializing the index variable to traverse the array in reverse order

    // Finding the length of the left segments for each element in reverse order
    while (index >= 0) {
        while (!que.empty() && a[que.back()] > a[index]) { // Popping elements from the deque
            int ind = que.back();
            que.pop_back();
            leftl[ind] = ind - index - 1; // Calculating the length of the left segment
        }
        que.push_back(index--); // Pushing the current index into the deque
    }

    // Calculating the length of the left segment for the first elements
    while (!que.empty()) {
        int ind = que.back();
        que.pop_back();
        leftl[ind] = ind - index - 1;
    }

    long long ans = 0; // Initializing the variable to store the final answer

    // Calculating the answer by multiplying the element, left segment length, and right segment length for each element
    for (int i = 0; i < N; ++i) {
        ans += (long long) a[i] * (leftl[i] + 1) * (rightl[i] + 1);
    }

    // Printing the final answer
    cout << ans << endl;

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
