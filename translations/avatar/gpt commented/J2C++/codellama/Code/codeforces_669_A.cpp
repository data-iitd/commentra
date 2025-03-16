#include <iostream>
using namespace std;

int main() {
    // Declaring and initializing a variable to store the input integer
    int n;
    cin >> n;
    
    // Calling the solve function with the input integer
    solve(n);
    return 0;
}

// Defining the solve function
void solve(int n) {
    // Calculating and printing the result based on the input integer n
    // The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
    cout << (n / 3) * 2 + (n % 3 == 0 ? 0 : 1) << endl;
}

