#include <iostream>
using namespace std;

int main() {
    // Declare an array to hold 10 integers
    int v[10];
    
    // Initialize a variable to hold the sum of the integers
    int sum = 0;
    
    // Prompt the user to enter 10 integers and store them in the array
    for(int i = 0; i < 10; i++) {
        cin >> v[i];
    }
    
    // Calculate the sum of the integers stored in the array
    for(int i = 0; i < 10; i++) {
        sum += v[i];
    }
    
    // Output the calculated sum to the console
    cout << sum << endl;
    
    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
