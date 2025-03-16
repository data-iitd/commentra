
#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    // Scanner sc(cin);

    // Read the number of elements (n) and the threshold value (m)
    int n, m;
    cin >> n >> m;

    // Initialize two queues: one for the values and one for their original indices
    queue<int> q1;
    queue<int> q2;

    // Populate the queues with input values and their corresponding indices
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q1.push(x);
        q2.push(i);
    }

    // Variable to store the final answer (the index of the last processed element)
    int ans = 0;

    // Process the elements in the queue until it is empty
    while (!q1.empty()) {
        // Check if the front element of q1 is less than or equal to m
        if (q1.front() <= m) {
            // If yes, remove it from q1 and update the answer with the corresponding index from q2
            q1.pop();
            ans = q2.front();
            q2.pop();
        }
        // If the front element is greater than m
        else if (q1.front() > m) {
            // Remove the element, reduce it by m, and add it back to q1
            int x = q1.front();
            q1.pop();
            int val = x - m;
            q1.push(val);

            // Remove the index from q2 and add it back to maintain the order
            int val2 = q2.front();
            q2.pop();
            q2.push(val2);
        }
    }

    // Output the final answer
    cout << ans << endl;

    return 0;
}
