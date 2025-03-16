#include <iostream> // Include the iostream library for input and output operations
using namespace std;

int N, A; // Declare two integer variables N and A

int main() {
    // Read two integers from standard input
    cin >> N >> A;

    // Check if the remainder of N divided by 500 is less than or equal to A
    // If true, print "Yes"; otherwise, print "No"
    cout << (N % 500 <= A ? "Yes" : "No") << endl;

    return 0; // Return 0 to indicate successful completion of the program
}

