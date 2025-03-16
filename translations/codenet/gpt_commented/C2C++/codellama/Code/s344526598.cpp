#include<iostream>

int main(void)
{
    // Declare variables
    int i, j, x[10000];

    // Initialize the array x with zeros
    for(i = 0; i < 10000; i++){
        x[i] = 0;
    }

    // Read the first input value into the array
    i = 0;
    std::cin >> x[i];
    
    // Continue reading input values until a zero is encountered
    while(x[i] != 0){
        i++;
        std::cin >> x[i];
    }
    
    // Print the case number and the corresponding value from the array
    for(j = 0; j < i; j++){
        std::cout << "Case " << j + 1 << ": " << x[j] << std::endl;
    }
    
    return 0; // Indicate that the program ended successfully
}

