#include <iostream>
using namespace std;

int main() {
    int t; // Declaring the number of test cases
    cin >> t; // Reading the number of test cases
    int count = 0; // Initializing a counter to keep track of valid cases
    
    // Looping through each test case
    while (t-- > 0) {
        int a, b, c; // Declaring the three integers
        cin >> a >> b >> c; // Reading the three integers
        
        // Checking if at least one of the integers is equal to 1
        if ((a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1) || (a == 1 && b == 1 && c == 1)) {
            count++; // Incrementing the count if the condition is met
        }
    }
    
    // Outputting the total count of valid cases
    cout << count << endl;
    
    return 0;
}

