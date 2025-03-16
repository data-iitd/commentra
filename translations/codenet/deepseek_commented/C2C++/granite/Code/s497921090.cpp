
#include<iostream>  // Include the standard input/output library
using namespace std;  // Use the standard namespace
int main()  // Define the main function
{
    unsigned long long int n, a, b = 0, i, j;  // Declare variables to store the input number and the result
    cin >> n;  // Read the input number
    b = (n * (n - 1)) / 2;  // Calculate the result using the given formula
    cout << b << endl;  // Print the result
    return 0;  // Indicate that the program ended successfully
}
