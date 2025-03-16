#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class Scanner {
private:
    std::istream& in;
    std::string buffer;
    std::string::size_type pos;

    void pre() {
        if (pos >= buffer.size()) {
            std::getline(in, buffer);
            pos = 0;
        }
    }

public:
    Scanner(std::istream& is = std::cin) : in(is), pos(0) {}

    std::string next() {
        pre();
        std::string::size_type start = pos;
        while (pos < buffer.size() && buffer[pos] != ' ') {
            ++pos;
        }
        std::string result = buffer.substr(start, pos - start);
        ++pos;
        return result;
    }

    std::string nextLine() {
        pre();
        std::string result = buffer.substr(pos);
        pos = buffer.size();
        return result;
    }

    int nextInt() {
        return std::stoi(next());
    }

    std::vector<int> nextIntArray() {
        pre();
        std::vector<int> result;
        std::string::size_type start = pos;
        while (pos < buffer.size() && buffer[pos] != ' ') {
            ++pos;
        }
        result.push_back(std::stoi(buffer.substr(start, pos - start)));
        ++pos;
        return result;
    }

    std::map<int, bool> nextMap() {
        pre();
        std::map<int, bool> result;
        std::string::size_type start = pos;
        while (pos < buffer.size() && buffer[pos] != ' ') {
            ++pos;
        }
        result[std::stoi(buffer.substr(start, pos - start))] = true;
        ++pos;
        return result;
    }
};

int main() {
    Scanner sc;

    int n = sc.nextInt();
    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        int tmp = sc.nextInt();
        ans += 1.0 / tmp;
    }
    std::cout << std::fixed << std::setprecision(10) << 1.0 / ans << std::endl;

    return 0;
}
