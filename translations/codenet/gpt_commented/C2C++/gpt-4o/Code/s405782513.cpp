#include <iostream>
#include <vector>

int main() {
    // Declare a vector to hold three card values
    std::vector<int> c(3);
    
    // Continuously read three integers until EOF is reached
    while (std::cin >> c[0] >> c[1] >> c[2]) {
        // Initialize a vector to track the presence of cards
        std::vector<char> card(10, 0);
        int count = 0; // Initialize count of valid card positions
        int sum = c[0] + c[1]; // Calculate the sum of the first two card values
        
        // Mark the positions of the cards in the card vector
        for (int i = 0; i < 3; i++) {
            card[c[i] - 1] = 1; // Set the position corresponding to the card value
        }
        
        // Count how many card positions are available that do not exceed the total of 20
        for (int i = 0; i < 10; i++) {
            // Check if the card position is unoccupied and if adding it to the sum does not exceed 20
            if (card[i] == 0 && sum + i + 1 <= 20) {
                count++; // Increment the count for each valid position
            }
        }
        
        // Determine if there are at least 4 valid positions available
        if (count >= 4) {
            std::cout << "YES" << std::endl; // Output YES if there are enough valid positions
        } else {
            std::cout << "NO" << std::endl; // Output NO if there are not enough valid positions
        }
    }
    
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
