#include <iostream>
#include <vector>

int main() {
    // Read the number of rounds (n) and the number of George's complexities (m)
    int n, m;
    std::cin >> n >> m;
    
    // Read the complexities for each round into a list
    std::vector<int> round_complexity(n);
    for (int i = 0; i < n; i++) {
        std::cin >> round_complexity[i];
    }
    
    // Read George's complexities into another list
    std::vector<int> george_complexity(m);
    for (int i = 0; i < m; i++) {
        std::cin >> george_complexity[i];
    }
    
    // Initialize indices for both lists
    int i = 0, j = 0;
    
    // Iterate through both lists to compare complexities
    while (i < n && j < m) {
        // If the current round's complexity is less than or equal to George's complexity,
        // move to the next round
        i += 1 * (round_complexity[i] <= george_complexity[j]);
        
        // Always move to the next complexity of George
        j += 1;
    }
    
    // Output the number of rounds that George cannot handle
    std::cout << n - i << std::endl;
}

