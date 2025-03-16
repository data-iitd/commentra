

#include<iostream>
// Include the standard input/output library header file

int main()
{
    int a, b, c;
    // Declare three integer variables: a, b, and c

    std::cin>>a>>b>>c;
    // Use the std::cin object to read three integers from the standard input
    // and assign them to the variables a, b, and c respectively

    if(a<b && b<c)
    {
        std::cout<<"Yes\n";
        // If the condition a < b && b < c is true, print the string "Yes"
        // followed by a newline character to the standard output
    }
    else
    {
        std::cout<<"No\n";
        // If the condition a < b && b < c is false, print the string "No"
        // followed by a newline character to the standard output
    }

    return 0;
    // End the main function with a return statement of 0, indicating that
    // the program has run successfully
}

