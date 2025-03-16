#include<iostream> // Include the iostream library for input and output
using namespace std; // Use the standard namespace

int main() {
    int x; // Declare an integer variable x to store user input
    cin >> x; // Read an integer value from the user and store it in x

    // Check if the input value x is greater than or equal to 1200
    if (x >= 1200) 
        cout << "ARC" << endl; // If true, output "ARC"
    else 
        cout << "ABC" << endl; // If false, output "ABC"
    
    return 0; // Return 0 to indicate successful completion of the program
}
