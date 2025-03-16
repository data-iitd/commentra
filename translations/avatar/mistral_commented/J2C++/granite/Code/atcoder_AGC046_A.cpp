
// Importing necessary C++ libraries
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <cctype>
#include <utility>
#include <numeric>
#include <iomanip>
#include <climits>
#include <cstring>
#include <fstream>

// Main function starts here
int main() {

    // Creating FastReader object to read input
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Creating variables to store input
    int x;
    std::cin >> x;

    // Initializing count variable to 0
    int count = 0;

    // Initializing temporary variable tmp with the value of x
    int tmp = x;

    // Setting x to 0
    x = 0;

    // Starting a while loop that runs until x is equal to 360
    while (x!= 360) {

        // Adding the value of tmp to x
        x = x + tmp;

        // If x is greater than 360, then subtract 360 from it
        if (x > 360) {
            x = x - 360;
        }

        // Incrementing the count variable
        count++;
    }

    // Printing the value of count to the console
    std::cout << count << std::endl;

    // End of code
    return 0;
}

// FastReader class starts here
class FastReader {

public:
    // Method to read a string token
    std::string next() {
        std::string str;
        std::cin >> str;
        return str;
    }

    // Method to read an integer input
    int nextInt() {
        int num;
        std::cin >> num;
        return num;
    }

    // Method to read a long integer input
    long long nextLong() {
        long long num;
        std::cin >> num;
        return num;
    }

    // Method to read a double input
    double nextDouble() {
        double num;
        std::cin >> num;
        return num;
    }

    // Method to read a full line of input
    std::string nextLine() {
        std::string str;
        std::getline(std::cin, str);
        return str;
    }
};