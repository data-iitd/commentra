#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // Define the input size and initialize an empty list for answers
    int q;
    cin >> q;
    vector<int> ans(2, 0);

    // Import heapq module for priority queue implementation
    priority_queue<int> p1;
    priority_queue<int, vector<int>, greater<int>> p2;

    // Initialize variables for sums of balls and priority queues
    int sum_b = 0;
    int sum_p1 = 0;
    int sum_p2 = 0;

    // Iterate through each query
    for (int i = 0; i < q; i++) {
        // Check if the current query is to find the answer
        if (i == q - 1) {
            // Check if both piles have equal number of balls
            if (p1.size() == p2.size()) {
                // Calculate the answer and print it
                cout << -p2.top() << " " << sum_p1 - p1.size() * -p2.top() + p2.size() * -p2.top() - sum_p2 + sum_b << endl;
            } else {
                // Calculate the answer and print it
                cout << p1.top() << " " << sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b << endl;
            }
        }

        // Else, the current query is to add balls to a pile
        else {
            // Add the number of balls to the total sum
            sum_b += i;

            // If pile p1 is empty, add the ball to it
            if (p1.size() == 0) {
                p1.push(i);
                sum_p1 += i;
            }

            // Else, check if the ball can be added to pile p1
            else if (p1.top() <= i) {
                p1.push(i);
                sum_p1 += i;
            }

            // Else, add the ball to pile p2 and adjust the sums accordingly
            else {
                p2.push(-i);
                sum_p2 += i;
                sum_p1 -= i;
                sum_p2 -= i;
            }

            // Adjust the priority queues if necessary
            if (p1.size() < p2.size()) {
                int k = p2.top();
                p1.push(-k);
                sum_p2 += k;
                sum_p1 -= k;
            }

            if (p1.size() - 1 > p2.size()) {
                int k = p1.top();
                p2.push(-k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }

    return 0;
}

