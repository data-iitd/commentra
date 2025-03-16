// Include necessary headers
#include <iostream>
#include <string>

int main() {
    // Declare two variables, n and s
    int n;
    std::string s;

    // Read the input from the standard input
    std::cin >> n >> s;

    // Count the occurrences of "ABC" in the string s
    int count = 0;
    std::string target = "ABC";
    size_t pos = s.find(target);
    
    while (pos != std::string::npos) {
        count++;
        pos = s.find(target, pos + 1);
    }

    // Print the result
    std::cout << count << std::endl;

    return 0;
}

// <END-OF-CODE>
