// Include necessary headers
#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

// Function to split a string into a vector of integers
vector<int> splitToInts(const string& line) {
    vector<int> result;
    stringstream ss(line);
    string item;
    while (ss >> item) {
        result.push_back(stoi(item));
    }
    return result;
}

// Function to calculate the number of points within a distance D from the origin
void Run(istream& r, ostream& w) {
    // Read the first line of input containing N and D
    string firstLine;
    getline(r, firstLine);
    vector<int> firstLineValues = splitToInts(firstLine);
    int N = firstLineValues[0], D = firstLineValues[1];

    // Initialize a counter variable count to 0
    int count = 0;

    // Iterate through each line of input
    for (int i = 0; i < N; ++i) {
        string line;
        getline(r, line);
        vector<int> lineValues = splitToInts(line);

        // Calculate the Euclidean distance of the current point from the origin (0,0)
        double distance = sqrt(static_cast<double>(lineValues[0] * lineValues[0] + lineValues[1] * lineValues[1]));

        // If the distance is less than or equal to D, increment the counter
        if (distance <= D) {
            count++;
        }
    }

    // Write the final result to the output stream
    w << count << endl;
}

// Main function
int main() {
    Run(cin, cout);
    return 0;
}

// <END-OF-CODE>
