#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Initialize a string variable h with the value "NO"
    string h = "NO";

    // Read a line of input from the console
    string line;
    getline(cin, line);

    // Split the line into an array of strings using space character as delimiter
    stringstream ss(line);
    string list[3];
    for (int i = 0; i < 3; i++) {
        ss >> list[i];
    }

    // Parse the first three elements of the array as integers x, a, and y
    int x = stoi(list[0]);
    int a = stoi(list[1]);
    int y = stoi(list[2]);

    // Check if any of the numbers x, a, or y are equal to 5 or 7
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        // If any of the numbers satisfy the condition, check if their sum is equal to 17
        if (x + y + a == 17) {
            // If the sum is equal to 17, set the value of h to "YES"
            h = "YES";
        }
    }

    // Print the value of h to the console
    cout << h << endl;

    return 0;
}

