#include <iostream>

using namespace std;

int main() {
    long long pandu, vundu, urdu, c = 0; // Declare four long long integers to store user input and a variable for accumulation

    cin >> pandu; // Read the first long integer input from the user
    cin >> vundu; // Read the second long integer input from the user
    cin >> urdu;  // Read the third long integer input from the user

    // The for loop iterates from 1 to urdu (inclusive)
    // In each iteration, it calculates the product of i and pandu and adds it to the variable c
    for (int i = 1; i <= urdu; i++) {
        c += i * pandu;
    }

    // The if-else statement checks if the value of c is less than vundu
    // If it is, the program prints "0". Otherwise, it prints the difference between c and vundu
    if (c < vundu) {
        cout << "0";
    } else {
        cout << c - vundu;
    }

    return 0;
}

// <END-OF-CODE>
