#include <iostream>
using namespace std;

int main()
{
    // Declare a variable named 'age' and assign it the value of an integer input from the user
    int age;
    cin >> age;

    // Check if the value of 'age' is equal to 1
    if (age == 1)
    {
        // If the condition is met, print 'Hello World'
        cout << "Hello World" << endl;
    }
    else
    {
        // If the condition is not met, declare two variables 'a' and 'b' and assign them the values of two integer inputs from the user
        int a, b;
        cin >> a >> b;

        // Print the sum of 'a' and 'b'
        cout << a + b << endl;
    }

    return 0;
}
