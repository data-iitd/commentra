#include <iostream> // Step 1: Include the iostream library for input/output.

int main() // Step 2: Define the main function.
{
    int i, j, x[10000]; // Step 3: Declare integer variables i, j, and an array x with a size of 10000.

    for(i = 0; i < 10000; i++) { // Step 4: Initialize the array x with zeros.
        x[i] = 0;
    }
    i = 0; // Step 5: Initialize i to 0.
    std::cin >> x[i]; // Step 6: Read an integer from the input and store it in x[0].
    
    while(x[i] != 0) { // Step 7: Use a while loop to read integers into the array x until a zero is entered.
        i++;
        std::cin >> x[i];
    }
    
    for(j = 0; j < i; j++) { // Step 8: Use a for loop to print the integers stored in the array x.
        std::cout << "Case " << j + 1 << ": " << x[j] << std::endl;
    }
    
    return 0; // Step 9: Return 0 to indicate successful execution.
}

// <END-OF-CODE>
