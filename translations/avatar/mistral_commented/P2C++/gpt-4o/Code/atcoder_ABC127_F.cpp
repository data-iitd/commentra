#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Define the input size and initialize an empty vector for answers
    int q;
    cin >> q;
    vector<int> ans(2, 0);

    // Initialize empty priority queues for piles p1 and p2
    priority_queue<int, vector<int>, greater<int>> p1; // Min-heap for p1
    priority_queue<int> p2; // Max-heap for p2

    // Initialize variables for sums of balls and priority queues
    long long sum_b = 0;
    long long sum_p1 = 0;
    long long sum_p2 = 0;

    // Iterate through each query
    for (int i = 0; i < q; i++) {
        int query_type;
        cin >> query_type;

        // Check if the current query is to find the answer
        if (query_type == 2) {
            // Check if both piles have equal number of balls
            if (p1.size() == p2.size()) {
                // Calculate the answer and print it
                cout << -p2.top() << " " << sum_p1 - p1.size() * -p2.top() + p2.size() * -p2.top() - sum_p2 + sum_b << endl;
            } else {
                // Calculate the answer and print it
                cout << p1.top() << " " << sum_p1 - p1.size() * p1.top() + p2.size() * p1.top() - sum_p2 + sum_b << endl;
            }
        } else {
            int ball_value, pile_type;
            cin >> pile_type >> ball_value;

            // Add the number of balls to the total sum
            sum_b += ball_value;

            // If pile p1 is empty, add the ball to it
            if (p1.empty()) {
                p1.push(ball_value);
                sum_p1 += ball_value;
            }
            // Else, check if the ball can be added to pile p1
            else if (p1.top() <= ball_value) {
                p1.push(ball_value);
                sum_p1 += ball_value;
            }
            // Else, add the ball to pile p2 and adjust the sums accordingly
            else {
                p2.push(ball_value);
                sum_p2 += ball_value;
                sum_p1 -= ball_value;
                sum_p2 -= ball_value;
            }

            // Adjust the priority queues if necessary
            if (p1.size() < p2.size()) {
                int k = p2.top();
                p2.pop();
                p1.push(-k);
                sum_p2 += k;
                sum_p1 -= k;
            }

            if (p1.size() - 1 > p2.size()) {
                int k = p1.top();
                p1.pop();
                p2.push(-k);
                sum_p1 -= k;
                sum_p2 += k;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
