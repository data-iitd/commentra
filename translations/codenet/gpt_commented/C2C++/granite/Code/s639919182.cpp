
#include <iostream>

int main(void)
{
    // Declare an array to hold 10 integers
    int v[10];
    
    // Initialize a variable to hold the sum of the integers
    int sum = 0;
    
    // Declare a loop variable
    int i;
    
    // Prompt the user to enter 10 integers and store them in the array
    for(i = 0; i < 10; i++)
        std::cin >> v[i];
    
    // Calculate the sum of the integers stored in the array
    for(i = 0; i < 10; i++)
        sum += v[i];
    
    // Output the calculated sum to the console
    std::cout << sum << std::endl;
    
    // Return 0 to indicate successful completion of the program
    return 0;
}
