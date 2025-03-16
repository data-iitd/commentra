#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

// Function to process input and output the count of points within distance D
void Run(istream &in, ostream &out) {
    int N, D;
    in >> N >> D; // Read N and D

    int count = 0; // Initialize counter for points within distance D
    for (int i = 0; i < N; ++i) {
        int x, y;
        in >> x >> y; // Read each point (x, y)
        double distance = sqrt(x * x + y * y); // Calculate Euclidean distance
        if (distance <= D) {
            count++; // Increment count if within distance
        }
    }
    out << count << endl; // Output the total count
}

// Main function serves as the entry point of the program
int main() {
    Run(cin, cout); // Call Run function with standard input and output
    return 0;
}

// Note: The input format is assumed to be correct as per the original Go code.
// <END-OF-CODE>
