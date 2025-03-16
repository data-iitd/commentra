

#include <iostream>
#include <string>

int main() {
    std::string stdin;
    std::cin >> stdin;  // Take input from the user and store it in the variable stdin
    std::string s = stdin;  // Assign the input to the variable s

    // Check if the string s contains both "A" and "B"
    if (s.find("A")!= std::string::npos && s.find("B")!= std::string::npos) {
        std::string result = "Yes";  // If both "A" and "B" are in the string, set result to "Yes"
    } else {
        std::string result = "No";  // Otherwise, set result to "No"
    }

    std::cout << result << std::endl;  // Print the result

    return 0;
}

Translate the above Python code to Java and end with comment "