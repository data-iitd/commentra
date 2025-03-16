#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class Scanner {
public:
    Scanner() : r(std::cin) {}

    int NextInt() {
        std::string token;
        r >> token;
        return std::stoi(token);
    }

    std::vector<int> NextIntArray() {
        std::vector<int> result;
        std::string token;
        while (r >> token) {
            result.push_back(std::stoi(token));
            if (r.peek() == ' ') {
                r.ignore();
            } else {
                break;
            }
        }
        return result;
    }

private:
    std::istream& r;
};

int main() {
    Scanner sc;
    int n = sc.NextInt();
    double ans = 0.0;

    for (int i = 0; i < n; i++) {
        int tmp = sc.NextInt();
        ans += 1.0 / tmp;
    }

    std::cout << std::fixed << std::setprecision(10) << 1.0 / ans << std::endl;
    return 0;
}
