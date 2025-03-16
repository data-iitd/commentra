#include <iostream>

int main() {
    // Declare variables
    int key, i, j, len, a[101];
    
    // Read the length of the array
    std::cin >> len;
    
    // Read the elements of the array
    for(i = 0; i < len; i++) 
        std::cin >> a[i];

    // Perform insertion sort
    for(j = 1; j < len; j++) {
        // Print the current state of the array
        for(i = 0; i < len; i++) 
            std::cout << (i != 0 ? " " : "") << a[i];
        std::cout << std::endl; // Move to the next line after printing the array
        
        // Store the current element to be positioned
        key = a[j];
        
        // Shift elements of the sorted segment to the right
        for(i = j - 1; i >= 0 && a[i] > key; i--) 
            a[i + 1] = a[i];
        
        // Place the key in its correct position
        a[i + 1] = key;
    }

    // Print the sorted array
    for(i = 0; i < len; i++) 
        std::cout << (i != 0 ? " " : "") << a[i];
    std::cout << std::endl; // Move to the next line after printing the sorted array
    
    return 0; // End of the program
}

