#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the number of queries
    int q;
    cin >> q;
    // Initialize answers and sums
    vector<int> ans(2, 0);
    int sum_b = 0;
    int sum_p1 = 0;
    int sum_p2 = 0;

    // Initialize two heaps for managing two groups of numbers
    priority_queue<int> p1;
    priority_queue<int, vector<int>, greater<int>> p2;

    // Process each query
    for (int i = 0; i < q; i++) {
        // Read the query line and convert it to a list of integers
        vector<int> ql;
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            ql.push_back(x);
        }

        // If the query type is 2, perform a specific operation
        if (ql[0] == 2) {
            // If both heaps are of equal length, calculate and print the result based on p2
            if (p1.size() == p2.size()) {
                ans[0] = -p2.top();
                ans[1] = sum_p1 - p1.size() * -p2.top() + p2.size() * -p2.top() - sum_p2 + sum_b;
            } else {
                // If p1 is longer, calculate and print the result based on p1
                ans[0] = p1.top();
                ans[1] = sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b;
            }
            cout << ans[0] << " " << ans[1] << endl;
        } else {
            // If the query type is 1, update the heaps and sums
            sum_b += ql[2];  // Add the third element of the query to the sum_b

            // If p1 is empty, push the new value into p1
            if (p1.empty()) {
                p1.push(ql[1]);
                sum_p1 += ql[1];
            }
            // If the new value is greater than or equal to the smallest in p1, push it to p1
            else if (p1.top() <= ql[1]) {
                p1.push(ql[1]);
                sum_p1 += ql[1];
            }
            // Otherwise, push the negative of the new value into p2 (to maintain max-heap behavior)
            else {
                p2.push(-ql[1]);
                sum_p2 += ql[1];
            }

            // Balance the heaps if p1 has fewer elements than p2
            if (p1.size() < p2.size()) {
                int k = p2.top();  // Pop the largest from p2
                p2.pop();
                p1.push(-k);  // Push it to p1 (as positive)
                sum_p2 += k;  // Update sum_p2
                sum_p1 -= k;  // Update sum_p1
            }

            // Balance the heaps if p1 has more than one extra element compared to p2
            if (p1.size() - 1 > p2.size()) {
                int k = p1.top();  // Pop the smallest from p1
                p1.pop();
                p2.push(-k);  // Push it to p2 (as negative)
                sum_p1 -= k;  // Update sum_p1
                sum_p2 += k;  // Update sum_p2
        }
    }

    return 0;
}

