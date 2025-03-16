#include<iostream>

using namespace std;

int main() {
    // Declare an integer variable to hold the input value
    int x;

    // Read an integer value from the user and store it in variable x
    cin >> x;

    // Calculate the cube of the input value by multiplying it by itself twice
    x = x * x * x;

    // Print the result (the cube of the input value) to the console
    cout << x << endl;

    // Return 0 to indicate that the program finished successfully
    return 0;
}
