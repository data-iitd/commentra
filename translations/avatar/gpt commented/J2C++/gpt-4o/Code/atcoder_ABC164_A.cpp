#include <iostream> // Including the necessary header for input and output
#include <vector>   // Including the vector header for dynamic array
#include <sstream>  // Including the sstream header for string stream
#include <string>   // Including the string header for string manipulation

using namespace std;

int main() {
    // Initializing a vector to store the input strings
    vector<string> scList;
    string line;

    // Continuously read input lines until EOF
    while (getline(cin, line)) {
        scList.push_back(line);
    }

    // Splitting the first line of input into a string stream
    stringstream ss(scList[0]);
    int Sheep, Wolve;

    // Parsing the first number as the count of sheep
    ss >> Sheep;
    // Parsing the second number as the count of wolves
    ss >> Wolve;

    // Checking if the number of wolves is greater than or equal to the number of sheep
    if (Wolve >= Sheep) {
        // If wolves are greater than or equal to sheep, it's unsafe
        cout << "unsafe" << endl;
    } else {
        // If wolves are fewer than sheep, it's safe
        cout << "safe" << endl;
    }

    return 0;
}

// <END-OF-CODE>
