#include <iostream> // Including iostream for input/output
using namespace std;

int main() {
    // Reading an integer input from the user
    int n;
    cin >> n;

    // Calling the solve function with the input integer
    // The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
    cout << (n / 3) * 2 + (n % 3 == 0 ? 0 : 1) << endl;

    return 0;
}

// <END-OF-CODE>
