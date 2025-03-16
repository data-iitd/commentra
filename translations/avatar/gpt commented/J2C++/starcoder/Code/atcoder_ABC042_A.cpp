#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read a line of input and split it into an array of strings
    string line;
    getline(cin, line);
    string list[3];
    int i = 0;
    for (string s : line.split(" ")) {
        list[i] = s;
        i++;
    }
    
    // Parse the first three elements of the input into integers
    int x = stoi(list[0]);
    int a = stoi(list[1]);
    int y = stoi(list[2]);
    
    // Initialize a variable to hold the result, defaulting to "NO"
    string h = "NO";
    
    // Check if any of the numbers x, a, or y are either 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If the sum of x, a, and y equals 17, set the result to "YES"
        if (x + y + a == 17) {
            h = "YES";
        }
    }
    
    // Output the result
    cout << h << endl;
    
    return 0;
}
