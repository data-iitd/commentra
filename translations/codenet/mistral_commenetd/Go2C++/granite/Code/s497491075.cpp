

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function Run calculates the number of points within a square with side length D and center at (0,0)
void Run(istream& r, ostream& w) {
    // Initialize a new scanner object to read input
    Scanner sc(r);

    // Read the first line of input containing N and D
    vector<int> a = sc.ReadLine().Ints();
    int N = a[0], D = a[1];

    // Read N lines of input and store them in a vector called lines
    vector<vector<int>> lines = sc.ReadLines(N).Ints();

    // Initialize a counter variable count to 0
    int count = 0;

    // Iterate through each line in the lines vector
    for (const auto& line : lines) {
        // Calculate the Euclidean distance of the current line from the origin (0,0)
        double d = sqrt(line[0] * line[0] + line[1] * line[1]);

        // If the distance of the current line is less than or equal to D, increment the counter
        if (D >= d) {
            count++;
        }
    }

    // Write the final result to the output stream
    w << count << endl;
}

// main function calls the Run function with standard input and output streams
int main() {
    Run(cin, cout);
    return 0;
}

// Scanner structure to read input lines
class Scanner {
public:
    Scanner(istream& r) : sc(r) {}

    // Read a single line of input and return it as a Value object
    Value ReadLine() {
        string line;
        getline(sc, line);
        return Value(line);
    }

    // Read N lines of input and return them as a vector of Value objects
    Values ReadLines(int n) {
        Values a;
        for (int i = 0; i < n; i++) {
            a.push_back(ReadLine());
        }
        return a;
    }

private:
    istream& sc;
};

// Value structure to store a string value
class Value {
public:
    Value(const string& s) : s(s) {}

    // Return the string representation of the Value object
    string String() const {
        return s;
    }

    // Convert the Value object to an integer
    int Int() const {
        stringstream ss(s);
        int n;
        ss >> n;
        return n;
    }

    // Convert the Value object to a float
    float Float() const {
        stringstream ss(s);
        float f;
        ss >> f;
        return f;
    }

    // Split the Value object into a vector of strings based on whitespace
    vector<string> Strings() const {
        vector<string> a;
        stringstream ss(s);
        string token;
        while (getline(ss, token,'')) {
            a.push_back(token);
        }
        return a;
    }

    // Convert the Value object to a vector of integers
    vector<int> Ints() const {
        vector<int> a;
        for (const auto& token : Strings()) {
            a.push_back(stoi(token));
        }
        return a;
    }

    // Convert the Value object to a vector of floats
    vector<float> Floats() const {
        vector<float> a;
        for (const auto& token : Strings()) {
            a.push_back(stof(token));
        }
        return a;
    }

private:
    string s;
};

// Vector of Value objects
using Values = vector<Value>;

// Translate the above C++ code to Java and end with comment "