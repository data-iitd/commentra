#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

// Function to read integers from a string
vector<int> readInts(const string& line) {
    vector<int> result;
    stringstream ss(line);
    int number;
    while (ss >> number) {
        result.push_back(number);
    }
    return result;
}

// Main function to process input and output
void run(istream& in, ostream& out) {
    string line;

    // Read the first line which contains two integers N and D.
    getline(in, line);
    vector<int> firstLine = readInts(line);
    int N = firstLine[0], D = firstLine[1];

    // Initialize a counter to keep track of points within the given distance.
    int count = 0;

    // Read the next N lines which contain pairs of integers representing points.
    for (int i = 0; i < N; ++i) {
        getline(in, line);
        vector<int> point = readInts(line);
        // Calculate the Euclidean distance of the point from the origin.
        double distance = sqrt(point[0] * point[0] + point[1] * point[1]);
        // Check if the distance is within the given limit.
        if (D >= distance) {
            count++;
        }
    }

    // Write the count of points within the distance to the output.
    out << count << endl;
}

// Main function
int main() {
    run(cin, cout);
    return 0;
}

// <END-OF-CODE>
