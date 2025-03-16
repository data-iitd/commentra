#include <iostream>
#include <vector>
#include <string>

int main() {
    // Read two integers n and k from input
    int n, k;
    std::cin >> n >> k;

    // Read the string of values (v) from input
    std::string v;
    std::cin >> v;

    // Define the directions for movement: LEFT and RIGHT
    std::string d[2] = {"LEFT", "RIGHT"};

    // Determine if we should move LEFT or RIGHT based on the position k
    bool f = (k - 1 < n - k);

    // Calculate the minimum number of moves needed to reach the desired position
    int m = std::min(k - 1, n - k);

    // Initialize a vector to store the sequence of moves and prints
    std::vector<std::string> a;

    // Append the necessary number of LEFT or RIGHT moves to the vector based on the calculated minimum moves
    for (int i = 0; i < m; i++) {
        a.push_back(d[!f]);  // Append the opposite direction of f
    }

    // Append the print commands for each character in the string v
    // The slicing reverses the order of characters if moving RIGHT (f is true)
    for (char c : (f ? std::string(v.rbegin(), v.rend()) : v)) {
        a.push_back("PRINT " + std::string(1, c));  // Append the print command for the current character
        a.push_back(d[f]);                           // Append the direction for the next move
    }

    // Print the final sequence of moves and print commands, excluding the last move
    for (size_t i = 0; i < a.size() - 1; i++) {
        std::cout << a[i] << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
