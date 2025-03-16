
#include<iostream> // Including the standard input output library header file

using namespace std; // Using the standard namespace

int main() // Starting the main function
{
    int n; // Declaring an integer variable `n` to store the user input

    cout<<"Enter a number: "; // Printing a message to ask the user to enter a number
    cin>>n; // Reading an integer value from the standard input and storing it in the variable `n`

    if(n%1000==0) // Checking if the remainder of `n` when divided by 1000 is equal to 0
    {
        cout<<0<<endl; // If the condition is true, we print the value 0 to the standard output
    }
    else
    {
        cout<<((n/1000)+1)*1000-n<<endl; // If the condition is false, we calculate the number that is one thousand greater than the quotient of `n` when divided by 1000 and print that value to the standard output
    }

    return 0; // Ending the main function with a return value of 0
}

