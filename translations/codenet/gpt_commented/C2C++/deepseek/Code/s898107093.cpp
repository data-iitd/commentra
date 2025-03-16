#include <iostream>
#include <string>
#include <vector>
#include <cstring>

int main() {
    // Declare pointers for storing team names and initialize scores
    std::vector<std::string*> t, h;
    int n, taro = 0, hanako = 0, i;

    // Read the number of rounds (n) from input
    std::cin >> n;

    // Loop through each round to read team names and calculate scores
    for (i = 0; i < n; i++) {
        // Allocate memory for each team name (up to 100 characters)
        t.push_back(new std::string());
        h.push_back(new std::string());
        
        // Read team names for both players
        std::cin >> *t[i];
        std::cin >> *h[i];
        
        // Compare team names and update scores based on the comparison
        if (strcmp(t[i]->c_str(), h[i]->c_str()) < 0) {
            // If Hanako's team name is lexicographically smaller, she gets 3 points
            hanako += 3;
        }
        if (strcmp(t[i]->c_str(), h[i]->c_str()) > 0) {
            // If Taro's team name is lexicographically larger, he gets 3 points
            taro += 3;
        }
        if (strcmp(t[i]->c_str(), h[i]->c_str()) == 0) {
            // If both team names are the same, both players get 1 point
            taro += 1;
            hanako += 1;
        }
    }
    
    // Output the final scores of Taro and Hanako
    std::cout << taro << " " << hanako << std::endl;
    
    // Free the memory allocated for the pointers to team names
    for (i = 0; i < n; i++) {
        delete t[i];
        delete h[i];
    }
    
    return 0;
}
