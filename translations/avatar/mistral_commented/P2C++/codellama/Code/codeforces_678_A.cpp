
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Read a line of text from the standard input stream and convert it into a list of integers
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> vamshi;
    int z;
    while (iss >> z) {
        vamshi.push_back(z);
    }

    // Calculate the number of complete divisions of z into vamshi
    // Add 1 to account for the remainder
    // Multiply the result by z
    int result = (vamshi[0] / vamshi[1] + 1) * vamshi[1];

    // Print the result
    cout << result << endl;

    return 0;
}

