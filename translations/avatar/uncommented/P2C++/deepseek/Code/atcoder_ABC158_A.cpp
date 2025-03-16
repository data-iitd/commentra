#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::string result = "Yes";
    if (!(("A" in s) && ("B" in s))) {
        result = "No";
    }
    std::cout << result << std::endl;
    return 0;
}
