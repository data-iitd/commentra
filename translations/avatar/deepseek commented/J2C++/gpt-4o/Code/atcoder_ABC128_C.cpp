#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create a vector to store the states of switches
    int N, M;
    cin >> N >> M;

    vector<int> a(N, 0); // Initialize a vector of integers with N elements, all set to 0

    // Read M groups of integers, where each group represents a switch and its corresponding states
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int s;
            cin >> s;
            s--; // Convert to 0-based index
            a[s] |= (1 << i); // Update the state of the switch
        }
    }

    // Read the final state of each light
    int p = 0;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        p |= (x << i); // Update the final state
    }

    // Calculate the number of possible configurations of switch states that match the final state of the lights
    int ans = 0;
    for (int s = 0; s < (1 << N); s++) {
        int t = 0;
        for (int i = 0; i < N; i++) {
            if ((s >> i) & 1) { // Check if the i-th switch is on
                t ^= a[i]; // Update the current state
            }
        }
        if (p == t) { // Check if the current state matches the final state
            ans++;
        }
    }

    // Print the result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
