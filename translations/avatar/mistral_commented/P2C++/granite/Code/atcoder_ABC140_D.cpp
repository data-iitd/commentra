
#####
# Code
#####

# Include necessary libraries
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cstring>
#include <cassert>
#include <complex>
#include <iomanip>

// Define a class for segment count
class SegCnt {
private:
    std::queue<int> seg_cnt;

public:
    // Function to add a segment to the count
    void addSeg() {
        seg_cnt.push(1);
    }

    // Function to get the current segment count
    int getSegCnt() {
        return seg_cnt.size();
    }
};

// Define a function to parse input line by line
std::vector<std::string> parser() {
    std::vector<std::string> data;
    std::string line;
    while (std::getline(std::cin, line)) {
        data.push_back(line);
    }
    return data;
}

// Define a function to get the next token from the parser
std::string gw() {
    static std::vector<std::string> data = parser();
    static int pos = 0;
    if (pos == data.size()) {
        data.clear();
        return "";
    }
    return data[pos++];
}

// Define a function to get the next integer from the parser
int gi() {
    std::string data = gw();
    return atoi(data.c_str());
}

// Define a function to get the next long integer from the parser
long gl() {
    std::string data = gw();
    return atol(data.c_str());
}

// Define a function to get the next floating-point number from the parser
double gd() {
    std::string data = gw();
    return atof(data.c_str());
}

// Define a function to get the next string from the parser
std::string gs() {
    return gw();
}

// Define a function to print the answer
void answer(int n) {
    std::cout << n << std::endl;
}

// Define a function to print the answer
void answer(long n) {
    std::cout << n << std::endl;
}

// Define a function to print the answer
void answer(double n) {
    std::cout << std::fixed << n << std::endl;
}

// Define a function to print the answer
void answer(std::string s) {
    std::cout << s << std::endl;
}

// Define a function to print the answer
void answer(const char *s) {
    std::cout << s << std::endl;
}

// Define a function to print the answer
void answer(char *s) {
    std::cout << s << std::endl;
}

// Define a function to print the answer
void answer(bool b) {
    std::cout << (b? "YES" : "NO") << std::endl;
}

// Define a function to print the answer
template<typename T>
void answer(std::vector<T> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::vector<std::vector<T>> v) {
    for (const auto &line : v) {
        answer(line);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::set<T> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, int> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, T> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::string> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, T> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::vector<T>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::vector<T>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, T>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, T>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::string>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::string>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<std::string, std::vector<T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::vector<T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, std::string>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<std::string, std::vector<T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::vector<T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, std::map<T, T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, std::map<T, std::string>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, std::map<std::string, std::vector<T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::vector<T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, std::map<T, std::map<T, T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, std::map<T, std::map<T, std::string>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, std::map<T, std::map<std::string, std::vector<T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::vector<T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, std::map<T, std::map<T, std::map<T, T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, T>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<T, std::map<T, std::map<T, std::map<T, std::map<T, std::map<T, std::string>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> v) {
    for (const auto &x : v) {
        answer(x);
    }
}

// Define a function to print the answer
template<typename T>
void answer(std::ma