#include <iostream>
#include <vector>

int main() {
    int key, len;
    std::vector<int> a(101);
    
    // Step 1: Read the length of the array
    std::cin >> len;
    
    // Step 2: Read the elements of the array
    for(int i = 0; i < len; i++) std::cin >> a[i];

    // Step 3: Perform Insertion Sort
    for(int j = 1; j < len; j++) {
        // Print the array before each iteration
        for(int i = 0; i < len; i++) std::cout << (i != 0 ? " " : "") << a[i];
        std::cout << std::endl;
        
        // Store the current element to be inserted
        key = a[j];
        
        // Shift elements to the right to make space for the key
        int i;
        for(i = j - 1; i >= 0 && a[i] > key; i--) a[i + 1] = a[i];
        
        // Insert the key into the correct position
        a[i + 1] = key;
    }

    // Step 4: Print the sorted array
    for(int i = 0; i < len; i++) std::cout << (i != 0 ? " " : "") << a[i];
    std::cout << std::endl;
    
    return 0;
}

// <END-OF-CODE>
