// Including necessary C++ libraries
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

// Main class starts here
int main() {

    // Creating FastReader object to read input
    class FastReader {

        // Creating BufferedReader object to read input
        std::streambuf *cinbuf;
        std::streambuf *coutbuf;

        // Constructor method initializes BufferedReader object
        public:
        FastReader() {
            cinbuf = std::cin.rdbuf();
            std::cin.rdbuf(cinbuf);
            coutbuf = std::cout.rdbuf();
            std::cout.rdbuf(coutbuf);
        }

        // Method to read a string token
        std::string next() {
            std::string str;
            std::getline(std::cin, str);
            return str;
        }

        // Method to read an integer input
        int nextInt() {
            int x;
            std::string str = next();
            std::stringstream ss(str);
            ss >> x;
            return x;
        }

        // Method to read a long integer input
        long nextLong() {
            long x;
            std::string str = next();
            std::stringstream ss(str);
            ss >> x;
            return x;
        }

        // Method to read a double input
        double nextDouble() {
            double x;
            std::string str = next();
            std::stringstream ss(str);
            ss >> x;
            return x;
        }

        // Method to read a full line of input
        std::string nextLine() {
            std::string str;
            std::getline(std::cin, str);
            return str;
        }
    };

    // Creating FastReader object to read input
    FastReader sc;

    // Creating PrintWriter object to write output
    std::streambuf *coutbuf;
    std::streambuf *cerrbuf;
    std::ostream cout(coutbuf);
    std::ostream cerr(cerrbuf);

    // Reading the first integer input
    int x = sc.nextInt();

    // Initializing count variable to 0
    int count = 0;

    // Initializing temporary variable tmp with the value of x
    int tmp = x;

    // Setting x to 0
    x = 0;

    // Starting a while loop that runs until x is equal to 360
    while (x != 360) {

        // Adding the value of tmp to x
        x = x + tmp;

        // If x is greater than 360, then subtract 360 from it
        if (x > 360) {
            x = x - 360;
        }

        // Incrementing the count variable
        count++;
    }

    // Printing the value of count to the console using PrintWriter
    cout << count << std::endl;

    // Closing the PrintWriter and FastReader objects
    cout.rdbuf(coutbuf);
    cerr.rdbuf(cerrbuf);

    // Ending the program
    return 0;
}

