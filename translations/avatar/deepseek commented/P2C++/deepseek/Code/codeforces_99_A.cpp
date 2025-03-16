#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string l;
    std::getline(std::cin, l);  // Taking an input from the user
    std::vector<std::string> split_l;
    std::stringstream ss(l);
    std::string item;

    while (std::getline(ss, item, '.')) {  // Splitting the input into a list of strings separated by a period (.)
        split_l.push_back(item);
    }

    std::vector<char> s(split_l[0].begin(), split_l[0].end());  // Converting the first part of the split input into a list of characters
    std::vector<char> p(split_l[1].begin(), split_l[1].end());  // Converting the second part of the split input into a list of characters
    int i = p[0] - '0';  // Converting the first character of the second part into an integer

    // Checking if the last character of the first part is '9'
    if (s.back() == '9') {
        std::cout << "GOTO Vasilisa." << std::endl;  // Printing "GOTO Vasilisa." if the last character is '9'
    }
    // Checking if the last character of the first part is not '9' and the integer from the second part is less than 5
    else if (s.back() != '9' && i < 5) {
        std::string s_str(s.begin(), s.end());  // Joining the first part into a string
        std::cout << s_str << std::endl;  // Printing the joined string
    }
    // If the last character of the first part is not '9' and the integer from the second part is 5 or more
    else {
        std::string s_str(s.begin(), s.end());  // Joining the first part into a string
        int num = std::stoi(s_str) + 1;  // Incrementing the first part by 1
        std::cout << std::to_string(num) << std::endl;  // Printing the incremented string
    }

    return 0;
}
