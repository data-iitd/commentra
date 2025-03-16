#include <iostream>
#include <string>
#include <vector>

int main() {
    // Declare vectors for storing team names and initialize scores
    std::vector<std::string> t, h;
    int n, taro = 0, hanako = 0;

    // Read the number of rounds (n) from input
    std::cin >> n;

    // Resize vectors to hold team names for both players
    t.resize(n);
    h.resize(n);
    
    // Loop through each round to read team names and calculate scores
    for (int i = 0; i < n; i++) {
        // Read team names for both players
        std::cin >> t[i];
        std::cin >> h[i];
        
        // Compare team names and update scores based on the comparison
        if (t[i] < h[i]) {
            // If Hanako's team name is lexicographically smaller, she gets 3 points
            hanako += 3;
        }
        if (t[i] > h[i]) {
            // If Taro's team name is lexicographically larger, he gets 3 points
            taro += 3;
        }
        if (t[i] == h[i]) {
            // If both team names are the same, both players get 1 point
            taro += 1;
            hanako += 1;
        }
    }
    
    // Output the final scores of Taro and Hanako
    std::cout << taro << " " << hanako << std::endl;

    return 0;
}

// <END-OF-CODE>
