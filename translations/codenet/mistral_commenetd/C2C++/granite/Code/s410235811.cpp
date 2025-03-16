
#include<iostream>
// Include the standard input/output library header file.

int main(){
    int n;
    // Declare an integer variable 'n' to store the user input.

    std::cin>>n;
    // Use the std::cin object to read an integer value from the standard input
    // and store it in the variable 'n'.

    if(n%2==0){
        std::cout<<n/2<<"\n";
        // If the number 'n' is even, print the value of 'n/2' as the output.
    }
    else{
        std::cout<<(n/2)+1<<"\n";
        // If the number 'n' is odd, print the value of '(n/2)+1' as the output.
    }

    return 0;
}

