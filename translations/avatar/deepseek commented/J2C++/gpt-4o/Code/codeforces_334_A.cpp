#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the size of the grid
    int square = n * n; // Calculate the total number of elements

    vector<int> odd; // Vector to store odd numbers
    vector<int> even; // Vector to store even numbers

    // Separating numbers into odd and even vectors
    for (int i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even.push_back(i); // Add even numbers to the even vector
        } else {
            odd.push_back(i); // Add odd numbers to the odd vector
        }
    }

    int loop = square / n; // Calculate the number of rows/columns
    int div = loop / 2; // Calculate half the number of elements in each row/column

    // Debugging statement to print the value of div
    cerr << div << endl;

    // Nested loops to generate the pattern
    for (int i = 1; i <= loop; i++) {
        for (int j = 0; j < div; j++) {
            if (i % 2 == 1) {
                cout << odd.front() << " " << even.back() << " "; // Print odd and even numbers in reverse order for odd rows
                odd.erase(odd.begin()); // Remove the first element from odd
                even.pop_back(); // Remove the last element from even
            } else {
                cout << even.front() << " " << odd.back() << " "; // Print even and odd numbers in reverse order for even rows
                even.erase(even.begin()); // Remove the first element from even
                odd.pop_back(); // Remove the last element from odd
            }
        }
        cout << endl; // Move to the next line after each row
    }

    return 0; // End of the program
}

// <END-OF-CODE>
