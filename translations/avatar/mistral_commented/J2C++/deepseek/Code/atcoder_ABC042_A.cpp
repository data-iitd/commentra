#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    int x, a, y;
    char space;

    iss >> x >> space >> a >> space >> y;

    std::string h = "NO";

    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        if (x + y + a == 17) {
            h = "YES";
        }
    }

    std::cout << h << std::endl;

    return 0;
}
