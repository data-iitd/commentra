#include <iostream> // We include the iostream header for input and output
using namespace std; // We use the standard namespace

int main() { // The main function is the entry point of the program
    int n; // We declare an integer variable n to store the number of terms
    long long ans = 0; // We initialize a long long variable ans to 0, which will be used to store the answer

    // We read an integer n from the standard input stream using cin
    cin >> n;

    for (int i = 1; i <= n; i++) { // We start a for loop that iterates from 1 to n
        ans += (long long)i * (n / i) * ((n / i) + 1) / 2; // In each iteration of the loop, we calculate the contribution of i to the answer and add it to the ans variable
    }

    cout << ans << endl; // After the loop finishes, we print the value of ans to the standard output stream

    return 0; // We return 0 to indicate that the program finished successfully
}

// <END-OF-CODE>
