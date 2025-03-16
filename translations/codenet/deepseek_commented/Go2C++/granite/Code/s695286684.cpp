
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    std::string result = s;
    size_t pos = 0;
    while ((pos = result.find("2017", pos))!= std::string::npos) {
        result.replace(pos, 4, "2018");
        pos += 4;
    }
    std::cout << result << std::endl;
    return 0;
}
