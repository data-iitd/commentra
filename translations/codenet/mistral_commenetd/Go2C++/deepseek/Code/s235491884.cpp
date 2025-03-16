// C++ program to perform the same operations as the Go program
#include <iostream>
#include <string>

int main() {
    // Declare a variable 's' of type std::string
    std::string s;
    // Use 'std::getline' to read a string input from the standard input
    std::getline(std::cin, s);

    // Use 'std::string::count' to count the number of occurrences of the substring "o" in the string 's'
    int n = s.count("o");

    // Calculate the result by adding 700 to the product of 100 and the number of occurrences of "o" in the string
    int result = 700 + n * 100;
    // Use 'std::cout' to print the result to the standard output
    std::cout << result << std::endl;

    return 0;
}
