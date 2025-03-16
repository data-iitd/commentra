
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Create a BufferedReader to read input from the standard input stream
    string line;
    getline(cin, line);

    // Read the first line of input, split by spaces, and store in an array of strings
    vector<string> str;
    stringstream ss(line);
    string temp;
    while (ss >> temp) {
        str.push_back(temp);
    }

    // Create a StringTokenizer to parse the next line of input as integers
    getline(cin, line);
    stringstream st(line);
    int a, b;
    st >> a >> b;

    // Read another string from the input
    getline(cin, line);
    string u = line;

    // Check if the read string is equal to the first element of the array and print accordingly
    if (u == str[0]) {
        cout << a - 1 << " " << b << endl;
    } else {
        cout << a << " " << b - 1 << endl;
    }

    return 0;
}

