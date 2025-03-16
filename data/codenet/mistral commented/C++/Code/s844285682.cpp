
#include<iostream> // Include the iostream header file
using namespace std; // Use the std namespace

int main(){
    int a; // Declare an integer variable named a
    
    cout << "Enter the number of seconds: "; // Print a message to ask the user for the number of seconds
    cin >> a; // Read an integer value from the standard input stream and assign it to the variable a
    
    int hours = a / (60 * 60); // Extract the hours from the number of seconds
    int minutes = (a % (60 * 60)) / 60; // Extract the minutes from the remaining seconds
    int seconds = (a % (60 * 60)) % 60; // Extract the seconds from the remaining seconds
    
    cout << hours << ":" << minutes << ":" << seconds << endl; // Print the time representation of the number of seconds
    
    return 0; // Return 0 to indicate successful execution of the program
}