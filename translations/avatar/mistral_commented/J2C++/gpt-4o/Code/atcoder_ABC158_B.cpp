#include <iostream> // Including the iostream library for input and output
#include <cmath> // Including the cmath library for mathematical functions

using namespace std; // Using the standard namespace

long long A; // Global variable to hold the value of A
long long N; // Global variable to hold the value of N

bool isValidInput(long long n, long long a, long long b) {
    return (1 <= n && n <= pow(10, 18) && 0 <= a && 0 <= b && 0 < a + b && a + b <= pow(10, 18));
}

long long calculateK(long long n, long long a, long long b) {
    return n / (a + b);
}

bool remainingPartGreaterThanA(long long n, long long k, long long a, long long b) {
    return (n - k * (a + b)) > a;
}

void printResult(long long n, long long k, long long a, long long b) {
    long long result = 0;
    if (remainingPartGreaterThanA(n, k, a, b)) {
        result = a * k + (n - k * (a + b)) - (n - (k * (a + b) + a));
    } else {
        result = a * k + (n - k * (a + b));
    }
    cout << result << endl;
}

void printA() {
    cout << A << endl;
}

void printN() {
    cout << N << endl;
}

int main() {
    cin >> N; // Reading the first long integer `N` from the standard input
    cin >> A; // Reading the second long integer `A` from the standard input
    long long B; // Declaring a long long variable `B`
    cin >> B; // Reading the third long integer `B` from the standard input

    long long k = 0; // Initializing a long long variable `k` with the value 0

    if (isValidInput(N, A, B)) { // Checking if the input values are valid
        if (A + B <= N) { // Checking if the sum of `A` and `B` is less than or equal to `N`
            k = calculateK(N, A, B); // Calculating the number of times `A + B` can be added to `N` and storing the result in `k`

            if (remainingPartGreaterThanA(N, k, A, B)) { // Checking if the remaining part of `N` after subtracting `k * (A + B)` is greater than `A`
                printResult(N, k, A, B); // Printing the result
            } else {
                printResult(N, k, A, B); // Printing the result
            }
        } else if (A + B > N && A <= N) { // Checking if the sum of `A` and `B` is greater than `N`, but `A` is less than or equal to `N`
            printA(); // Printing the value of `A`
        } else { // If neither of the above conditions is true
            printN(); // Printing the value of `N`
        }
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
