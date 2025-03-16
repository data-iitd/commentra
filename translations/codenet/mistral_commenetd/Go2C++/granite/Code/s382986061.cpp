
#include <iostream>
#include <map>

int main() {
    // Read input values for N and K
    int N, K;
    std::cin >> N >> K;

    // Initialize an associative array (map) named as to store the frequency of each number
    std::map<int, int> as;

    // Initialize all elements of the map with zero frequency
    for (int i = 1; i <= N; i++) {
        as[i] = 0;
    }

    // Read K queries and process them
    for (int i = 0; i < K; i++) {
        // Read the length of the query
        int d;
        std::cin >> d;

        // Read the numbers in the query and increment their frequency in the map
        for (int j = 0; j < d; j++) {
            int a;
            std::cin >> a;
            as[a]++;
        }
    }

    // Initialize a variable named ans to store the answer
    int ans = 0;

    // Iterate through the map and check if the frequency of any number is zero
    // If yes, increment the value of ans
    for (auto it = as.begin(); it!= as.end(); it++) {
        if (it->second == 0) {
            ans++;
        }
    }

    // Print the final answer
    std::cout << ans << std::endl;

    // End of the code
    return 0;
}

