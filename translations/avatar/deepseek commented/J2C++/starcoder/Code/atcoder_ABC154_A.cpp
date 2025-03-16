
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    // Read the first line of input, split by spaces, and store in an array of strings
    string str[3];
    cin >> str[0] >> str[1] >> str[2];
    
    // Read the next line of input
    string line;
    getline(cin, line);
    
    // Create a StringTokenizer to parse the next line of input as integers
    istringstream iss(line);
    int a, b;
    iss >> a >> b;
    
    // Read another string from the input
    string u;
    getline(cin, u);
    
    // Check if the read string is equal to the first element of the array and print accordingly
    cout << (u.compare(str[0]) == 0? (a - 1) << " " << b : a << " " << (b - 1)) << endl;
    
    return 0;
}

