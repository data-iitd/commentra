#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int q;  // Read the number of queries
    cin >> q;
    vector<int> ans(2, 0);  // Initialize the answer list with two zeros
    priority_queue<int> p1;  // Initialize the first priority queue
    priority_queue<int, vector<int>, greater<int>> p2;  // Initialize the second priority queue
    int sum_b = 0;  // Initialize the sum of differences
    int sum_p1 = 0;  // Initialize the sum of the first priority queue
    int sum_p2 = 0;  // Initialize the sum of the second priority queue

    // Loop through each query
    for (int i = 0; i < q; i++) {
        int a, b, c;  // Read the query
        cin >> a >> b >> c;
        if (a == 2) {  // Check if the query type is 2
            if (p1.size() == p2.size()) {  // If the lengths of the two heaps are equal
                cout << -p2.top() << " " << sum_p1 - p1.size() * -p2.top() + p2.size() * -p2.top() - sum_p2 + sum_b << endl;  // Print the median and the sum of differences
            } else {  // If the lengths of the two heaps are not equal
                cout << p1.top() << " " << sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b << endl;  // Print the median and the sum of differences
            }
        } else {  // If the query type is not 2
            sum_b += c;  // Add the given value to the sum of differences
            if (p1.empty()) {  // If the first priority queue is empty
                p1.push(b);  // Push the value to the first priority queue
                sum_p1 += b;  // Update the sum of the first priority queue
            } else if (p1.top() <= b) {  // If the smallest element in the first priority queue is less than or equal to the given value
                p1.push(b);  // Push the value to the first priority queue
                sum_p1 += b;  // Update the sum of the first priority queue
            } else {  // If the given value is less than the smallest element in the first priority queue
                p2.push(-b);  // Push the negative value to the second priority queue
                sum_p2 += b;  // Update the sum of the second priority queue
            }
            if (p1.size() < p2.size()) {  // If the first priority queue has fewer elements than the second priority queue
                int k = p2.top();  // Pop the smallest element from the second priority queue
                p2.pop();
                p1.push(-k);  // Push the negative value to the first priority queue
                sum_p2 += k;  // Update the sum of the second priority queue
                sum_p1 -= k;  // Update the sum of the first priority queue
            }
            if (p1.size() - 1 > p2.size()) {  // If the first priority queue has one more element than the second priority queue
                int k = p1.top();  // Pop the smallest element from the first priority queue
                p1.pop();
                p2.push(-k);  // Push the negative value to the second priority queue
                sum_p1 -= k;  // Update the sum of the first priority queue
                sum_p2 += k;  // Update the sum of the second priority queue
            }
        }
    }
    return 0;
}

