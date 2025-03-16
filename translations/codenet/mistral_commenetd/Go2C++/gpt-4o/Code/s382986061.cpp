#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Initialize variables
    int N, K, d, a;

    // Read input values for N and K
    cin >> N >> K;

    // Initialize an associative array (unordered_map) to store the frequency of each number
    unordered_map<int, int> frequency;

    // Initialize all elements of the map with zero frequency
    for (int i = 1; i <= N; i++) {
        frequency[i] = 0;
    }

    // Read K queries and process them
    for (int i = 0; i < K; i++) {
        // Read the length of the query
        cin >> d;

        // Read the numbers in the query and increment their frequency in the map
        for (int j = 0; j < d; j++) {
            cin >> a;
            frequency[a]++;
        }
    }

    // Initialize a variable named ans to store the answer
    int ans = 0;

    // Iterate through the map and check if the frequency of any number is zero
    // If yes, increment the value of ans
    for (int i = 1; i <= N; i++) {
        if (frequency[i] == 0) {
            ans++;
        }
    }

    // Print the final answer
    cout << ans << endl;

    // End of the code
    return 0;
}
