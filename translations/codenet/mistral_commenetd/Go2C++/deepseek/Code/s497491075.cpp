#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>

class Scanner {
public:
    Scanner(std::istream& is) : is_(is) {}

    std::string ReadLine() {
        std::string line;
        std::getline(is_, line);
        return line;
    }

    std::vector<int> ReadInts(int n) {
        std::vector<int> ints;
        for (int i = 0; i < n; ++i) {
            std::string line = ReadLine();
            ints.push_back(std::stoi(line));
        }
        return ints;
    }

private:
    std::istream& is_;
};

class Value {
public:
    Value(const std::string& str) : str_(str) {}

    std::string String() const {
        return str_;
    }

    int Int() const {
        return std::stoi(str_);
    }

    double Float64() const {
        return std::stod(str_);
    }

    std::vector<std::string> Strings() const {
        std::vector<std::string> result;
        std::stringstream ss(str_);
        std::string token;
        while (ss >> token) {
            result.push_back(token);
        }
        return result;
    }

    std::vector<int> Ints() const {
        std::vector<int> result;
        std::stringstream ss(str_);
        int num;
        while (ss >> num) {
            result.push_back(num);
        }
        return result;
    }

    std::vector<double> Float64s() const {
        std::vector<double> result;
        std::stringstream ss(str_);
        double num;
        while (ss >> num) {
            result.push_back(num);
        }
        return result;
    }

private:
    std::string str_;
};

class Values : public std::vector<Value> {};

void Run(std::istream& is, std::ostream& os) {
    Scanner sc(is);
    Value firstLine = Value(sc.ReadLine());
    int N = firstLine.Int();
    int D = firstLine.Int();

    Values lines = sc.ReadInts(N);

    int count = 0;

    for (const auto& line : lines) {
        double d = std::sqrt(line[0] * line[0] + line[1] * line[1]);
        if (D >= d) {
            ++count;
        }
    }

    os << count << std::endl;
}

int main() {
    Run(std::cin, std::cout);
    return 0;
}
