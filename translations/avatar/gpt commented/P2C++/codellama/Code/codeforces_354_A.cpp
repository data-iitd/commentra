#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read input values: n (number of elements), L (left multiplier), R (right multiplier), QL (left penalty), QR (right penalty)
    int n, L, R, QL, QR;
    cin >> n >> L >> R >> QL >> QR;

    // Read the list of weights W
    vector<int> W(n);
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }

    // Initialize a vector to store cumulative sums, starting with 0 for the base case
    vector<int> sum_el(n + 1, 0);

    // Calculate cumulative sums of the weights
    for (int i = 1; i < n + 1; i++) {
        sum_el[i] = W[i - 1] + sum_el[i - 1];
    }

    // Calculate the initial answer based on the total weight and the right multiplier
    int answer = QR * (n - 1) + sum_el[n] * R;

    // Iterate through each element to find the minimum energy configuration
    for (int i = 1; i < n + 1; i++) {
        // Calculate the energy for the current configuration
        int energy = L * sum_el[i] + R * (sum_el[n] - sum_el[i]);

        // Adjust energy based on the position of the current element relative to the midpoint
        if (i > (n - i)) {
            // If the current index is in the right half, apply left penalty
            energy += (i - (n - i) - 1) * QL;
        } else if ((n - i) > i) {
            // If the current index is in the left half, apply right penalty
            energy += ((n - i) - i - 1) * QR;
        }

        // Update the answer if the current energy is less than the previously recorded answer
        if (energy < answer) {
            answer = energy;
        }
    }

    // Print the minimum energy found
    cout << answer << endl;

    return 0;
}

