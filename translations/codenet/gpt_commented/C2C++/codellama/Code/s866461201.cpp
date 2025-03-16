#include <iostream>

int main() {
    // Declare variables
    int n, fd[6] = {}, i, j; // n: number of heights, fd: frequency distribution array
    double height; // height: variable to store individual height input

    // Read the number of heights to be processed
    std::cin >> n;
    
    // Process each height input
    while(n--) {
        // Read the height from input
        std::cin >> height;
        
        // Increment the appropriate frequency distribution index based on height ranges
        if(height >= 185.0) 
            fd[5]++; // Count for height >= 185.0
        else if(height >= 180.0) 
            fd[4]++; // Count for height >= 180.0 and < 185.0
        else if(height >= 175.0) 
            fd[3]++; // Count for height >= 175.0 and < 180.0
        else if(height >= 170.0) 
            fd[2]++; // Count for height >= 170.0 and < 175.0
        else if(height >= 165.0) 
            fd[1]++; // Count for height >= 165.0 and < 170.0
        else 
            fd[0]++; // Count for height < 165.0
    }

    // Output the frequency distribution as a histogram
    for(i = 0; i < 6; i++) {
        std::cout << i + 1 << ":"; // Print the category number (1 to 6)
        
        // Print asterisks corresponding to the frequency count for each category
        for(j = 0; j < fd[i]; j++)
            std::cout << '*';
        
        std::cout << std::endl; // Move to the next line after printing the asterisks
    }
    
    return 0; // Indicate successful completion of the program
}

