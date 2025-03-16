

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Initialize the scanner for reading input from the standard input
    cin.tie(0);
    ios::sync_with_stdio(false);

    // Read the number of shops N and the number of customers M from the standard input
    int N, M;
    cin >> N >> M;
    // Initialize a vector of shop data structures named s with a size of N
    vector<pair<int, int>> s(N);
    // For each shop in the vector
    for (int i = 0; i < N; i++) {
        // Read the capacity 'a' and demand 'b' of the shop from the standard input
        int a, b;
        cin >> a >> b;
        // Create a new shop data structure with the read values and assign it to the i-th position in the vector
        s[i] = {a, b};
    }
    // Sort the vector in ascending order based on the 'a' field of each shop
    sort(s.begin(), s.end());

    // Initialize a variable named total to store the total capacity used by the shops
    int total = 0;
    // For each shop in the sorted vector
    for (auto e : s) {
        // Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
        int n = min(e.second, M);
        // Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
        total += n * e.first;
        // Decrease the maximum demand by the number of customers served by the shop
        M -= n;
        // If the maximum demand becomes zero, break the loop
        if (M == 0) {
            break;
        }
    }
    // Print the total capacity used by the shops
    cout << total << endl;

    return 0;
}

