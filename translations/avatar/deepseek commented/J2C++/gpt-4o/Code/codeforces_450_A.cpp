#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Read the first integer input, which represents the number of elements and the second integer input, which is the threshold value

    queue<int> q1; // Initialize queue to store the elements
    queue<int> q2; // Initialize queue to store the indices

    for (int i = 1; i <= n; i++) {
        int element;
        cin >> element; // Read each element
        q1.push(element); // Add it to q1
        q2.push(i); // Add the corresponding index to q2
    }

    int ans = 0; // Initialize ans to store the result

    while (!q1.empty()) { // Continue the loop until q1 is empty
        if (q1.front() <= m) { // Check if the front element of q1 is less than or equal to m
            ans = q2.front(); // Assign the corresponding index to ans
            q1.pop(); // Remove the front element from q1
            q2.pop(); // Remove the corresponding index from q2
        } else { // Check if the front element of q1 is greater than m
            int x = q1.front(); // Get the front element of q1
            q1.pop(); // Remove the front element from q1
            int val = x - m; // Subtract m from the element
            q1.push(val); // Add the result back to q1
            int val2 = q2.front(); // Get the corresponding index from q2
            q2.pop(); // Remove the corresponding index from q2
            q2.push(val2); // Add the index back to the end of q2
        }
    }

    cout << ans << endl; // Print the index of the last remaining element
    return 0;
}

// <END-OF-CODE>
