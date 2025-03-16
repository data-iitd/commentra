
#include <iostream>
#include <map>

using namespace std;

int main() {
    int N, K, d, a;
    map<int, int> as;

    // Read input values for N and K
    cin >> N >> K;

    // Initialize an associative array (map) named as to store the frequency of each number
    for (int i = 1; i <= N; i++) {
        as[i] = 0;
    }

    // Read K queries and process them
    for (int i = 0; i < K; i++) {
        // Read the length of the query
        cin >> d;

        // Read the numbers in the query and increment their frequency in the map
        for (int j = 0; j < d; j++) {
            cin >> a;
            as[a]++;
        }
    }

    // Initialize a variable named ans to store the answer
    int ans = 0;

    // Iterate through the map and check if the frequency of any number is zero
    // If yes, increment the value of ans
    for (auto it = as.begin(); it != as.end(); it++) {
        if (it->second == 0) {
            ans++;
        }
    }

    // Print the final answer
    cout << ans << endl;

    // End of the code
    return 0;
}

