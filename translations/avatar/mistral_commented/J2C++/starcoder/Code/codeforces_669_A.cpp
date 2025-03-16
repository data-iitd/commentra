
#include <iostream> // Include the standard I/O library
using namespace std; // Use the standard namespace

int main() {
    int n; // Declare an integer variable 'n' to store the input number

    // Read the input number from the console and store it in the 'n' variable
    cout << "Enter a number: ";
    cin >> n;

    // Call the'solve' method to calculate and print the result
    solve(n);

    return 0;
}

//'solve' method to calculate and print the result
void solve(int n) {
    // Calculate the result and print it to the console
    cout << (n / 3) * 2 + (n % 3 == 0? 0 : 1) << endl;
}

