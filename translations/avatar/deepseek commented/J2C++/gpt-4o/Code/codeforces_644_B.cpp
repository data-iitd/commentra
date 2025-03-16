#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Main function to manage task processing with a buffer.
 */
int main() {
    int n, b;
    cin >> n >> b; // Read the number of tasks and buffer size
    vector<long long> ans(n); // Vector to store task completion times
    deque<long long> q; // Deque to manage buffer

    /**
     * Process each task
     */
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d; // Read the task's start time and duration

        /**
         * Remove completed tasks from the front of the queue
         */
        while (!q.empty() && q.front() <= t) {
            q.pop_front();
        }

        /**
         * Check if the task can be added to the buffer
         */
        if (q.size() < b) {
            ans[i] = (q.empty() ? t : q.back()) + d;
            q.push_back(ans[i]);
        } else {
            ans[i] = -1;
        }
    }

    /**
     * Output the completion times of all tasks
     */
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/* <END-OF-CODE> */
