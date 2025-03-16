#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string l;
    std::cin >> l;

    // Split the input string into two parts using '.' as the delimiter
    std::string::size_type pos = l.find('.');
    std::string s = l.substr(0, pos);
    std::string p = l.substr(pos + 1);

    // Extract the first character from the second part and convert it to an integer
    int i = p[0] - '0';

    // Check if the last character of the first part is '9'
    if (s[s.length() - 1] == '9') {
        // If it is '9', print the message "GOTO Vasilisa."
        std::cout << "GOTO Vasilisa." << std::endl;
    // Check if the last character is not '9' and the integer i is less than 5
    } else if (s[s.length() - 1] != '9' && i < 5) {
        // If both conditions are true, join the list of characters into a string and print it
        std::cout << s << std::endl;
    } else {
        // If the last character is not '9' and i is 5 or more
        // Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
        int num = std::stoi(s) + 1;
        std::cout << std::to_string(num) << std::endl;
    }

    return 0;
}
