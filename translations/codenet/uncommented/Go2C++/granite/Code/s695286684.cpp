
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::cout << std::string(s).replace(0, 4, "2018") << std::endl;
    return 0;
}
// END-OF-CODE

The above C++ code is a translation of the given Go code. It reads a string from the input, replaces the first 4 characters with "2018", and prints the modified string to the output.