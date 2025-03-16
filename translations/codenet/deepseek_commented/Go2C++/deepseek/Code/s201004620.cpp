#include <iostream>
#include <string>

int main() {
    // Declare a string variable S to store the weather input
    std::string S;
    
    // Read a string input from the user and store it in S
    std::cin >> S;
    
    // Use a switch statement to determine the weather based on the input
    if (S == "Sunny") {
        // If the input is "Sunny", print "Cloudy"
        std::cout << "Cloudy" << std::endl;
    } else if (S == "Cloudy") {
        // If the input is "Cloudy", print "Rainy"
        std::cout << "Rainy" << std::endl;
    } else if (S == "Rainy") {
        // If the input is "Rainy", print "Sunny"
        std::cout << "Sunny" << std::endl;
    }
    
    return 0;
}
