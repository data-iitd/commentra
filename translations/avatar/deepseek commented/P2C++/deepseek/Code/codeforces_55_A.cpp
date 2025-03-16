#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Take an integer input from the user
    while (n % 2 == 0) {  // Check if the number is even and keep dividing by 2 until odd
        n /= 2;
    }
    if (n == 1) {  // Check if the number has been reduced to 1
        cout << 'YES' << endl;  // Print 'YES' if the original number was a power of 2
    } else {
        cout << 'NO' << endl;  // Print 'NO' if the original number was not a power of 2
    }
