#include<stdio.h>  // Include the standard input/output library
int main(){       // Define the main function, the entry point of the program
    int n;        // Declare an integer variable to store the input value
    scanf("%d",&n);  // Read an integer input from the user and store it in the variable n
    if(n%2==0){    // Check if the number n is even
        printf("%d\n",n/2);  // If n is even, print half of n
    }
    else{          // If n is not even
        printf("%d\n",(n/2)+1);  // Print half of n plus one
    }
    return 0;     // Return 0 to indicate successful execution
}
