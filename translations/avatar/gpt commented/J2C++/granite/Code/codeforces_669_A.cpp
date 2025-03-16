
#include <iostream> // Importingiostream for input/output operations
#include <string> // Importing string for string manipulation

using namespace std;

int main() {
    // Creating a string variable to store the input
    string input;
    
    // Reading an integer input from the user
    getline(cin, input);
    
    // Converting the input string to an integer
    int n = stoi(input);
    
    // Calling the solve method with the input integer
    solve(n);
    
    return 0;
}

void solve(int n) {
    // Calculating and printing the result based on the input integer n
    // The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
    cout << (n / 3) * 2 + (n % 3 == 0? 0 : 1) << endl;
}

