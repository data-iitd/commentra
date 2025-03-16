#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Mon represents a monster with x-coordinate and height
struct Mon {
    int x, h;
};

// Custom comparator for sorting Mon structures
bool operator<(const Mon &a, const Mon &b) {
    return a.x < b.x;
}

// Node represents a node in the priority queue with x-coordinate and damage
struct Node {
    int x, h;
};

// Custom comparator for priority queue
bool operator<(const Node &a, const Node &b) {
    return a.x > b.x; // Min-heap based on x-coordinate
}

int main() {
    // Read input values N, D, and A
    int N, D, A;
    cin >> N >> D >> A;

    // Initialize a vector of Mon structures
    vector<Mon> M(N);

    // Read x and h values for each Mon and store them in the M vector
    for (int i = 0; i < N; i++) {
        cin >> M[i].x >> M[i].h;
    }

    // Sort the M vector based on x-coordinates
    sort(M.begin(), M.end());

    // Initialize a priority queue called q
    priority_queue<Node> q;

    // Initialize answer variable ans to 0 and total variable total to 0
    long long ans = 0;
    long long total = 0;

    // Iterate through each Mon in the sorted M vector
    for (int i = 0; i < N; i++) {
        // Current Mon
        Mon m = M[i];

        // While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
        while (!q.empty() && q.top().x < m.x) {
            // Pop the first Node from the priority queue
            total -= q.top().h;
            q.pop();
        }

        // If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
        if (total < m.h) {
            long long damage = m.h - total;
            ans += damage;
            q.push({m.x + 2 * D, damage});
            total += damage;
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
