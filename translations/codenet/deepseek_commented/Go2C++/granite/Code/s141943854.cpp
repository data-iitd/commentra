

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string sage;
    getline(cin, sage); // Read input from standard input

    if (sage == "1") {
        cout << "Hello World" << endl; // Print "Hello World" if input is "1"
    } else if (sage == "2") {
        int sum = 0;
        for (int i = 0; i < 2; i++) {
            string numStr;
            getline(cin, numStr); // Read input from standard input
            int num = stoi(numStr); // Convert string to integer
            sum += num; // Add the integer to the sum
        }
        cout << sum << endl; // Print the sum of the two integers
    }

    return 0;
}

