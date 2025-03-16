#include <iostream> // Importing necessary I/O libraries for file handling and other operations
#include <vector>   // Importing vector for dynamic array handling
#include <string>   // Importing string for string handling
#include <sstream>  // Importing stringstream for input handling
#include <algorithm> // Importing algorithm for max function

using namespace std;

class InputReader {
public:
    InputReader(istream &stream) : reader(stream) {} // Constructor to initialize the input stream

    string next() {
        string token;
        reader >> token; // Reading the next token
        return token; // Returning the next token
    }

    int nextInt() {
        return stoi(next()); // Parsing the next token as an integer
    }

    long long nextLong() {
        return stoll(next()); // Parsing the next token as a long long
    }

    double nextDouble() {
        return stod(next()); // Parsing the next token as a double
    }

private:
    istream &reader; // Reference to the input stream
};

class Task {
public:
    void solve(InputReader &in, ostream &out) {
        int n = in.nextInt(); // Reading the number of elements
        vector<int> array(1001, 0); // Initializing a vector to count occurrences

        for (int i = 0; i < n; i++) { // Looping through each element
            int index = in.nextInt(); // Reading the current element
            array[index]++; // Incrementing the count of the current element
        }

        int countMax = -1; // Initializing the maximum count to -1
        for (int i = 1; i < array.size(); i++) { // Looping through the array to find the maximum count
            countMax = max(countMax, array[i]); // Updating the maximum count if necessary
        }

        if (n % 2 == 0) { // Checking if n is even
            if (countMax <= n / 2) { // Checking if the maximum count is less than or equal to half of n
                out << "YES" << endl; // Printing "YES" if the condition is met
            } else {
                out << "NO" << endl; // Printing "NO" if the condition is not met
            }
        } else { // If n is odd
            if (countMax <= n / 2 + 1) { // Checking if the maximum count is less than or equal to half of n rounded up
                out << "YES" << endl; // Printing "YES" if the condition is met
            } else {
                out << "NO" << endl; // Printing "NO" if the condition is not met
            }
        }
    }
};

int main() {
    InputReader in(cin); // Creating an InputReader object to read input
    Task solver; // Creating an instance of the Task class
    solver.solve(in, cout); // Calling the solve method of the Task class
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
