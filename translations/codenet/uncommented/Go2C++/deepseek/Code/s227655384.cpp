#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

std::vector<std::string> ReadLongLines(int times) {
    std::vector<std::string> result(times);
    std::string line;
    for (int i = 0; i < times; ++i) {
        std::getline(std::cin, result[i]);
    }
    return result;
}

class Console {
public:
    Console() : out(std::cout.rdbuf()) {}
    ~Console() { out.flush(); }
    template<typename T>
    Console& operator<<(const T& x) {
        out << x;
        return *this;
    }
    void PrintList(const std::vector<int>& list) {
        for (size_t i = 0; i < list.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << list[i];
        }
        std::cout << std::endl;
    }
private:
    std::ostream& out;
};

int main() {
    Console con;

    std::map<int, bool> m;
    auto lines = ReadLongLines(4);
    std::istringstream iss(lines[1]);
    std::string token;
    while (std::getline(iss, token, ' ')) {
        int n = std::stoi(token);
        m[n] = !m[n];
    }

    std::vector<int> result;
    std::istringstream iss2(lines[3]);
    while (std::getline(iss2, token, ' ')) {
        int n = std::stoi(token);
        m[n] = !m[n];
    }
    for (const auto& pair : m) {
        if (pair.second) {
            result.push_back(pair.first);
        }
    }
    std::sort(result.begin(), result.end());
    for (int num : result) {
        con << num << std::endl;
    }

    return 0;
}
