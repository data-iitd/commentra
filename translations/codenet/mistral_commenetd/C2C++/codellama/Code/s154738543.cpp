
#include<iostream> // Including the standard input/output library

using namespace std; // Using the standard namespace

int main(){ // Main function declaration

    int x, y; // Declaring two integer variables x and y

    cout << "Enter a number: "; // Printing a message to ask user for input
    cin >> x; // Reading an integer value from the user and storing it in variable x

    y = x * x * x; // Assigning the value of x cubed to variable y

    cout << "The cube of " << x << " is " << y << endl; // Printing the message with the input number and its cube

    return 0; // Indicating successful execution of the program
}

