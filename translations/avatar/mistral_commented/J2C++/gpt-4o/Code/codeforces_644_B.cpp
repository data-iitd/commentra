#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using vectors
#include <deque>    // Including the deque library for using double-ended queues

using namespace std; // Using the standard namespace

int main() { // Defining the main function
    int n, b; // Declaring variables n and b
    cin >> n >> b; // Reading the values of n and b from standard input
    vector<long long> ans(n); // Creating a vector of long long type named ans with a size of n
    deque<long long> q; // Creating an empty deque of long long type named q

    for (int i = 0; i < n; i++) { // Starting a for loop that iterates from 0 to n-1
        int t, d; // Declaring variables t and d
        cin >> t >> d; // Reading the current test case's values t and d from standard input

        // The following while loop is used to remove the smallest element from the deque if it is less than or equal to the current test case's first integer value t
        while (!q.empty() && q.front() <= t) {
            q.pop_front(); // Removing the smallest element from the deque
        }

        // The following if statement checks whether the size of the deque is less than or equal to the value of the variable b
        if (q.size() <= b) {
            // If the condition is true, then the answer for the current test case is the sum of the last element in the deque and the difference d
            ans[i] = (q.empty() ? t : q.back()) + d;
            // Adding the answer to the deque
            q.push_back(ans[i]);
        } else {
            // If the condition is false, then the answer for the current test case is -1
            ans[i] = -1;
        }
    }

    // The following for loop is used to print the answers for all the test cases
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " "; // Printing the answer for the current test case followed by a space
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
