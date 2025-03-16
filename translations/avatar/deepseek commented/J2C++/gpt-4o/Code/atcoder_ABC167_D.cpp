#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Main {
public:
    void doIt() {
        // Read the number of elements N and the value K
        int N;
        long long K;
        cin >> N >> K;

        // Read the array A with N elements, adjusting each element by -1 for 0-based indexing
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            A[i]--; // Adjust for 0-based indexing
        }

        // Set to track visited indices
        unordered_set<int> used;

        // Vectors to store index and position information
        vector<int> idx(N);
        vector<int> pos(N);

        // Initialize variables for cycle detection
        int next = 0, cur = 0;

        // Detect the cycle in the array A
        while (used.find(next) == used.end()) {
            used.insert(next);
            idx[next] = cur;
            pos[cur] = next;
            next = A[next];
            cur++;
        }

        // Calculate the length of the cycle and adjust the position based on K
        long long a = cur - idx[next];
        long long b = idx[next];
        int ans = (int)((10000 * a + K - b) % a + b);

        // Adjust the answer if necessary based on the cycle length
        if (b > K) ans = (int)K;

        // Output the final position
        cout << pos[ans] + 1 << endl; // Adjust for 1-based indexing
    }
};

int main() {
    Main().doIt();
    return 0;
}

// <END-OF-CODE>
