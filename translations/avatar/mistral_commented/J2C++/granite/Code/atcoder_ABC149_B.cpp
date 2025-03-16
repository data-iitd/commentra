

#include <iostream> // Including necessary C++ utility headers
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <utility>
#include <climits>
#include <cassert>
#include <random>
#include <chrono>

using namespace std;

class Main {
public:
    long long A, B, K; // Declaring variables A, B, and K of type long long
    long long x, y; // Declaring variables x and y of type long long

    Main(string input) { // Constructor for the Main class that takes a string input as a parameter
        stringstream ss(input); // Creating a stringstream object and passing the input string as a parameter
        string token; // Declaring a string variable named token

        getline(ss, token,''); // Reading the first token from the stringstream and assigning it to variable A
        A = stoll(token); // Parsing the first token into a long long value and assigning it to variable A

        getline(ss, token,''); // Reading the second token from the stringstream and assigning it to variable B
        B = stoll(token); // Parsing the second token into a long long value and assigning it to variable B

        getline(ss, token,''); // Reading the third token from the stringstream and assigning it to variable K
        K = stoll(token); // Parsing the third token into a long long value and assigning it to variable K
    }

    void calc() { // Method to perform the calculations
        x = A; // Assigning the value of A to x
        y = B; // Assigning the value of B to y

        x = A - K; // Subtracting K from A and assigning the result to x

        if (x < 0) { // Checking if x is negative
            y = B + x; // If x is negative, adding the absolute value of x to B and assigning the result to y
            x = 0; // Setting x to zero
        }

        if (y < 0) { // Checking if y is negative
            y = 0; // If y is negative, setting it to zero
        }
    }

    string showResult() { // Method to display the results
        stringstream ss; // Creating a stringstream object
        ss << x << " " << y; // Adding the values of x and y to the stringstream separated by a space character
        return ss.str(); // Returning the string representation of the stringstream object
    }
};

int main() {
    string input = "100 200 150"; // Example input string
    Main ins(input); // Creating an instance of the Main class and passing the input string as a parameter
    ins.calc(); // Calling the calc() method to perform the calculations
    string result = ins.showResult(); // Calling the showResult() method to display the results
    cout << result << endl; // Printing the results to the console
    return 0;
}

