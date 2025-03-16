#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation
#include <algorithm> // Including the algorithm library for counting occurrences

int main() {
    std::string s; // Declaring a string variable to store user input
    std::cin >> s; // Reading input from the user and storing it in the variable s

    int n = std::count(s.begin(), s.end(), 'o'); // Counting the number of occurrences of 'o' in the string s and storing the result in n
    std::cout << 700 + n * 100 << std::endl; // Printing the final score based on the count of 'o' characters
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
