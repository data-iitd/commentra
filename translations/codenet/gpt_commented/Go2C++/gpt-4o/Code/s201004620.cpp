#include <iostream>
#include <string>

int main() {
    // Declare a variable to hold the weather condition input
    std::string S;
    
    // Read the weather condition from standard input
    std::cin >> S;
    
    // Use a switch statement to determine the next weather condition based on the input
    if (S == "Sunny") {
        // If the input is "Sunny", print "Cloudy" as the next condition
        std::cout << "Cloudy" << std::endl;
    } else if (S == "Cloudy") {
        // If the input is "Cloudy", print "Rainy" as the next condition
        std::cout << "Rainy" << std::endl;
    } else if (S == "Rainy") {
        // If the input is "Rainy", print "Sunny" as the next condition
        std::cout << "Sunny" << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
