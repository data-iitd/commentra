#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

// Define a structure for a monster with position x and health h
struct Mon {
    int x, h;
};

// Function to calculate the ceiling of a/b
int ceil(int a, int b) {
    return (a + b - 1) / b; // This is a more efficient way to calculate ceiling
}

// Main function to execute the program logic
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D, A;
    cin >> N >> D >> A; // Read N, D, A
    vector<Mon> M(N); // Create a vector to hold monsters

    for (int i = 0; i < N; i++) {
        cin >> M[i].x >> M[i].h; // Read each monster's position and health
    }

    // Sort monsters by their position
    sort(M.begin(), M.end(), [](const Mon &a, const Mon &b) {
        return a.x < b.x;
    });

    queue<pair<int, int>> q; // Queue to manage damage (position, damage)
    int ans = 0; // Variable to count the total number of attacks
    int total = 0; // Variable to track total damage dealt

    // Iterate through each monster
    for (int i = 0; i < N; i++) {
        Mon m = M[i]; // Get the current monster

        // Remove monsters from the queue that are out of range
        while (!q.empty() && q.front().first < m.x) {
            total -= q.front().second; // Decrease total damage by the damage of the popped monster
            q.pop();
        }

        // If the total damage is less than the monster's health
        if (total < m.h) {
            m.h -= total; // Reduce the monster's health by total damage
            int count = ceil(m.h, A); // Calculate how many attacks are needed
            ans += count; // Increment the total attack count
            int damage = count * A; // Calculate the total damage dealt to this monster
            q.push({m.x + 2 * D, damage}); // Add the monster's damage to the queue
            total += damage; // Update the total damage
        }
    }

    cout << ans << endl; // Output the total number of attacks
    return 0;
}

// <END-OF-CODE>
