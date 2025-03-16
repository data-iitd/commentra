#include <iostream> // Importing iostream for input and output operations
#include <string> // Importing string for string operations

void solve(int n) {
    // Calculating the result based on the given logic
    std::cout << (n / 3) * 2 + (n % 3 == 0 ? 0 : 1) << std::endl; // Printing the result to the console
}

int main() {
    int n;
    std::cin >> n; // Reading an integer input from the user and storing it in variable n
    solve(n); // Calling the solve method with the input value n
    return 0;
}

