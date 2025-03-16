#include<stdio.h>
// Include the standard input/output library header file.

int main(){
    int n;
    // Declare an integer variable 'n' to store the user input.

    scanf("%d",&n);
    // Use the scanf function to read an integer value from the standard input
    // and store it in the variable 'n'.

    if(n%2==0){
        printf("%d\n",n/2);
        // If the number 'n' is even, print the value of 'n/2' as the output.
    }
    else{
        printf("%d\n",(n/2)+1);
        // If the number 'n' is odd, print the value of '(n/2)+1' as the output.
    }

    return 0;
}