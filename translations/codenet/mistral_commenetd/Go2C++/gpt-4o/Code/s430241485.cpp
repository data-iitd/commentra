#include <iostream> // Include the iostream library for input and output

int main() { // Define the main function, entry point of our program
    // Declare two variables, s and t, both of type string
    std::string s, t;

    // Use std::cin to read input from the standard input (keyboard)
    // and store it in variables s and t respectively
    std::cin >> s >> t;

    // Print the concatenated string of t and s using std::cout
    std::cout << t + s << std::endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
