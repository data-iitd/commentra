#include <iostream>
#include <unordered_map>

using namespace std;

// Declare global variables for the number of elements (N), number of groups (K), 
// and temporary variables (d for group size, a for element).
int N, K;
int d, a;

int main() {
    // Read the total number of elements (N) and the number of groups (K) from input.
    cin >> N >> K;

    // Initialize a map to count occurrences of each element, with keys from 1 to N.
    unordered_map<int, int> as;
    for (int i = 1; i <= N; i++) {
        as[i] = 0; // Set initial count of each element to 0.
    }

    // Process each group of elements.
    for (int i = 0; i < K; i++) {
        // Read the size of the current group (d).
        cin >> d;
        // Read each element in the group and increment its count in the map.
        for (int j = 0; j < d; j++) {
            cin >> a;
            as[a]++; // Increment the count for the element a.
        }
    }

    // Initialize a counter for elements that are not present in any group.
    int ans = 0;
    // Iterate through the counts of each element in the map.
    for (const auto& pair : as) {
        // If an element's count is 0, it means it was not present in any group.
        if (pair.second == 0) {
            ans++; // Increment the counter for missing elements.
        }
    }

    // Output the total count of elements that were not present in any group.
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
