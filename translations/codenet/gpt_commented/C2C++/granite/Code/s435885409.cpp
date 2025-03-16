
#include <string>
#include <iostream>

// Function to calculate the score based on user input
int calc_score() {                                                              
    int out = 0; // Initialize the number of outs
    std::string str; // Buffer to store user input
    int score = 0; // Initialize the score
    int base = 0; // Initialize the number of players on base
    
    // Loop until there are 3 outs
    while (out < 3) {                                                           
        std::cin >> str; // Read user input into str
        
        // Check if the input is "OUT"
        if (str == "OUT") {                                                   
            out++; // Increment the out count
        } 
        // Check if the input is "HIT"
        else if (str == "HIT") {                                               
            // If all bases are occupied, score a point
            if (base == 3) {                                                    
                score++; // Increment the score
            } else {                                                            
                base++; // Move a player to the next base
            }                                                                   
        } 
        // Check if the input is "HOMERUN"
        else if (str == "HOMERUN") {                                           
            score += (base + 1); // Score based on players on base plus the hitter
            base = 0; // Reset bases after a homerun
        }                                                                       
    }                                                                           
    
    // Return the calculated score
    return score;                                                               
}

// Main function to execute the program
int main(void) {                                                                
    int n; // Variable to hold the number of innings
    int inning = 0; // Initialize the inning count
    
    // Read the number of innings from user input
    std::cin >> n;                                                              
    
    // Loop through the number of innings
    while (inning < n) {                                                        
        std::cout << calc_score() << std::endl; // Calculate and print the score for each inning
        inning++; // Increment the inning count
    }                                                                           
    
    // Return 0 to indicate successful execution
    return 0;                                                                   
}


