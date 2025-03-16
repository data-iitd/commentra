#include <iostream>
using namespace std;

int task4(int A, int B, int n) {
    // Iterate through a range of possible values for X from -1000 to 1000
    for (int X = -1000; X <= 1000; X++) {
        // Check if the equation A * (X ** n) equals B
        if (A * (X ** n) == B) {
            // If a solution is found, return the value of X
            return X;
        }
    }
    // If no solution is found in the range, return a message indicating no solution
    return "No solution";
}

int main() {
    // Take input from the user and split it into three variables A, B, and n
    string input;
    cin >> input;
    string A = input.substr(0, input.find(" "));
    string B = input.substr(input.find(" ") + 1, input.find(" ", input.find(" ") + 1) - input.find(" ") - 1);
    string n = input.substr(input.find(" ", input.find(" ") + 1) + 1);

    // Call the task4 function with the converted integer values of A, B, and n, and print the result
    cout << task4(stoi(A), stoi(B), stoi(n)) << endl;

    return 0;
}

