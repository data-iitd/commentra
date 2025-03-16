#include <iostream>
#include <string>

int main() {
    int n; // Declaring an integer variable to store the number of inputs
    std::string s; // Declaring a string variable to store the input string
    std::cin >> n >> s; // Reading input from the user and storing it in n and s

    // Counting the occurrences of "ABC" in s
    int count = 0;
    std::string target = "ABC";
    size_t pos = s.find(target);
    while (pos != std::string::npos) {
        count++;
        pos = s.find(target, pos + 1); // Move to the next position
    }

    std::cout << count << std::endl; // Printing the result
    return 0;
}

// <END-OF-CODE>
