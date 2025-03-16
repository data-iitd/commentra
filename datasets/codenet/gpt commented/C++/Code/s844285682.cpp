#include<iostream> // Include the iostream library for input and output operations
using namespace std;

int main() {
    int a, b; // Declare two integer variables a and b
    
    // Read an integer input from the user, which represents time in seconds
    cin >> a;
    
    // Calculate and display the time in hours, minutes, and seconds
    // a/(60*60) calculates the number of hours
    // a%(60*60)/60 calculates the number of minutes
    // a%(60*60)%60 calculates the remaining seconds
    cout << a/(60*60) << ":" << a%(60*60)/60 << ":" << a%(60*60)%60 << endl;
    
    return 0; // Return 0 to indicate that the program ended successfully
}
