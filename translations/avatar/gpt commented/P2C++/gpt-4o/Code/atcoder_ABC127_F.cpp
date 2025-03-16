#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Read the number of queries
    int q;
    cin >> q;

    // Initialize answers and sums
    long long sum_b = 0;
    long long sum_p1 = 0;
    long long sum_p2 = 0;

    // Initialize two heaps for managing two groups of numbers
    priority_queue<int, vector<int>, greater<int>> p1; // Min-heap for p1
    priority_queue<int> p2; // Max-heap for p2

    // Process each query
    for (int i = 0; i < q; ++i) {
        int query_type, value, additional_value;
        cin >> query_type;

        if (query_type == 2) {
            // If both heaps are of equal length, calculate and print the result based on p2
            if (p1.size() == p2.size()) {
                cout << -p2.top() << " " << sum_p1 - p1.size() * -p2.top() + p2.size() * -p2.top() - sum_p2 + sum_b << endl;
            } else {
                // If p1 is longer, calculate and print the result based on p1
                cout << p1.top() << " " << sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b << endl;
            }
        } else {
            cin >> value >> additional_value; // Read the value and additional value
            sum_b += additional_value; // Add the additional value to sum_b

            // If p1 is empty, push the new value into p1
            if (p1.empty()) {
                p1.push(value);
                sum_p1 += value;
            } 
            // If the new value is greater than or equal to the smallest in p1, push it to p1
            else if (p1.top() <= value) {
                p1.push(value);
                sum_p1 += value;
            } 
            else {
                // Otherwise, push the new value into p2 (to maintain max-heap behavior)
                p2.push(value);
                sum_p2 += value;
            }

            // Balance the heaps if p1 has fewer elements than p2
            if (p1.size() < p2.size()) {
                int k = p2.top(); // Pop the largest from p2
                p2.pop();
                p1.push(k); // Push it to p1
                sum_p2 -= k; // Update sum_p2
                sum_p1 += k; // Update sum_p1
            }

            // Balance the heaps if p1 has more than one extra element compared to p2
            if (p1.size() - 1 > p2.size()) {
                int k = p1.top(); // Pop the smallest from p1
                p1.pop();
                p2.push(k); // Push it to p2
                sum_p1 -= k; // Update sum_p1
                sum_p2 += k; // Update sum_p2
            }
        }
    }

    return 0;
}
// <END-OF-CODE>
