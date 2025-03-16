
#include <iostream> 
#include <string> 
#include <cstdlib> 

int main() { 
    // Create a Scanner object to read input from the user
    std::cin.sync_with_stdio(false); 
    std::cin.tie(nullptr); 

    // Read a long integer value from the user
    long long a; 
    std::cin >> a; 

    // Read a string value from the user
    std::string b; 
    std::cin >> b; 

    // Initialize an empty string to build the integer representation
    std::string bStr = ""; 

    // Loop through each character in the string 'b'
    for (char c : b) { 
        // If the character is not a '.', append it to bStr
        if (c!= '.') { 
            bStr += c; 
        } 
    } 

    // Convert the built string (bStr) to an integer
    int bInt = std::stoi(bStr); 

    // Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
    long long result = (a * bInt) / 100; 

    // Print the result to the console
    std::cout << result << std::endl; 

    return 0; 
}
