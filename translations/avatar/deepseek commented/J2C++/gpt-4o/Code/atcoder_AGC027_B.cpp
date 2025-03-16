#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Main {
public:
    void solve() {
        // Read the number of points N and the target value X
        int N;
        long long X;
        cin >> N >> X;

        // Initialize a vector to store the positions of N points
        vector<long long> x(N);
        vector<long long> xsum(N + 1, 0);

        // Read the positions of the points into the vector x and calculate the cumulative sum
        for (int i = 0; i < N; i++) {
            cin >> x[i];
            xsum[i + 1] = xsum[i] + x[i];
        }

        // Initialize ans with a value calculated using the total sum of positions and the given X value
        long long ans = X * N + 5 * xsum[N];

        // Iterate over possible values of i, which represents the number of points to be removed
        for (int i = 1; i < N; i++) {
            long long cost = X * i + 5 * (xsum[N] - xsum[N - i]);

            // For each value of i, calculate the cost of removing i points and update ans if a better cost is found
            for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) {
                if (cost > ans) {
                    break;
                }
                cost += j * (xsum[k] - xsum[max(k - i, 0)]);
            }
            ans = min(ans, cost);
        }

        // Print the minimum cost found
        cout << ans + N * X << endl;
    }
};

int main() {
    Main().solve();
    return 0;
}

// <END-OF-CODE>
