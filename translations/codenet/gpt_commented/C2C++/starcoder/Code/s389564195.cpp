#include <iostream>

using namespace std;

int main() {
    // Declare two integer variables: x for input and kotae for storing the result
    int x, kotae;

    // Prompt the user to enter an integer value
    cin >> x;

    // Calculate the cube of the input value x and store it in kotae
    kotae = x * x * x;

    // Output the result (the cube of x) to the console
    cout << kotae << endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

