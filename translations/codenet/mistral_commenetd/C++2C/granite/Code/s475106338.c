
#include <stdio.h> // Include the standard input/output library for input/output operations

int main(void){ // The main function is the entry point of the program
    int i, t, n; // Declare three integer variables: i for the loop counter, t for the user input, and n for the number of items

    // The for loop runs 4 times, each time reading user input and processing it accordingly
    for(i=0; i<4; i++){
        scanf("%d %d", &t, &n); // Read two integers from the user: t and n

        // Check the value of t and process the input accordingly
        if(t==1){
            printf("%d\n", 6000*n); // If t is 1, print the result of multiplying n by 6000 and ending the line
        }
        else if(t==2){
            printf("%d\n", 4000*n); // If t is 2, print the result of multiplying n by 4000 and ending the line
        }
        else if(t==3){
            printf("%d\n", 3000*n); // If t is 3, print the result of multiplying n by 3000 and ending the line
        }
        else if(t==4){
            printf("%d\n", 2000*n); // If t is 4, print the result of multiplying n by 2000 and ending the line
        }
    }
}
