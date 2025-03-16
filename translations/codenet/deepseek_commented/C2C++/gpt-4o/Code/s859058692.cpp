#include <iostream> // Include the iostream library for input/output

int main() 
{
    long sum = 0; // Declare and initialize the sum variable
    int m, n, min, max; // Declare variables for the current input, number of inputs, min, and max
    std::cin >> n; // Read the number of inputs

    // Loop through each input
    for(int i = 0; i < n; i++) {
        std::cin >> m; // Read the current input
        sum += m; // Update the sum with the current input

        // Check if it's the first input to set initial min and max values
        if(i == 0) {
            min = m;
            max = m;
        }

        // Update the min value if the current input is smaller
        if(min > m) {
            min = m;
        }

        // Update the max value if the current input is larger
        if(max < m) {
            max = m;
        }
    }

    // Output the minimum, maximum, and sum of the inputs
    std::cout << min << " " << max << " " << sum << std::endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
