
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Read a list of space-separated integers as input from the standard input
    // and convert each integer to its corresponding Python integer type using the int() function
    vector<int> a;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int value;
    while (ss >> value) {
        a.push_back(value);
    }

    // Iterate over the elements of the list a using the enumerate() function
    // which returns a tuple containing the index and the value of each element
    for (int index = 0; index < a.size(); index++) {
        // Check if the current value is equal to zero
        if (a[index] == 0) {
            // Print the index of the first zero to the standard output
            cout << index + 1 << endl;
            // Terminate the loop using the break statement
            break;
        }
    }

    return 0;
}

