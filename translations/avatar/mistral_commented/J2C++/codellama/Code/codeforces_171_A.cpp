// Importing necessary headers
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <random>
#include <complex>

// Defining a static inner class FastReader for reading input
class FastReader {
    private:
        std::ifstream in;
        std::string s;
        std::stringstream ss;
        std::string tmp;

    public:
        FastReader() {
            in.open("input.txt");
        }

        // Method for reading next token
        std::string next() {
            while (ss.str().empty()) {
                if (in.eof()) {
                    return "";
                }
                std::getline(in, s);
                ss << s;
            }
            ss >> tmp;
            return tmp;
        }

        // Methods for reading specific types of input
        int nextInt() {
            return std::stoi(next());
        }

        long nextLong() {
            return std::stol(next());
        }

        double nextDouble() {
            return std::stod(next());
        }

        std::string nextLine() {
            std::string str = "" ;
            try {
                str = ss.str();
                ss.str("");
                ss.clear();
            } catch (std::exception& e) {
                std::cout << e.what() << std::endl;
            }
            return str;
        }
};

// Main method
int main() {
    // Creating an instance of FastReader
    FastReader sc;

    // Reading input for number of test cases
    int n = sc.nextInt();

    // Reading input for number of operations
    int m = sc.nextInt();

    // Calling reverse function for m and adding it to n
    int t = reverse(m);
    std::cout << t + n << std::endl;

    return 0;
}

// Function for reversing a number
int reverse(int n) {
    // Base case for numbers less than 10
    if (n < 10)
        return n * 10;

    // Initializing variables
    int t = n, r = 0;

    // Reversing the number
    while (t > 0) {
        // Adding the digit to the reversed number
        r = (r * 10) + t % 10;

        // Moving to the next digit
        t = t / 10;
    }

    // Returning the reversed number
    return r;
}

