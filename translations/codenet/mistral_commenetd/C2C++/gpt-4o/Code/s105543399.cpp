#include <iostream> // We include the iostream library for input/output

using namespace std; // We use the standard namespace

int main() { // The main function is the entry point of the program
    long long n, a, m, M, c, i; // We declare variables of type long long for numbers that can be very large
    c = 0; // We initialize the variable 'c' to zero
    m = 100000000; // We initialize 'm' to a very large positive number
    M = -100000000; // We initialize 'M' to a very large negative number

    // We read the first number 'n' from the standard input
    cin >> n;

    for(i = 1; i <= n; i++) { // We start a for loop that iterates 'n' times
        // We read the current number 'a' from the standard input
        cin >> a;

        // If the current number 'a' is greater than the current maximum number 'M', we update 'M' with 'a'
        if(a > M) {
            M = a;
        }

        // If the current number 'a' is smaller than the current minimum number 'm', we update 'm' with 'a'
        if(a < m) {
            m = a;
        }

        // We add the current number 'a' to the variable 'c'
        c += a;
    }

    // We print the minimum number 'm', the maximum number 'M', and the sum 'c' to the standard output
    cout << m << " " << M << " " << c << endl;

    // The main function returns zero to indicate successful execution
    return 0;
}

// <END-OF-CODE>
