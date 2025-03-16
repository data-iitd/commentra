#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
<<<<<<< HEAD
    int N, D, X;
    int num_of_chocolate = 0;
    int counter;
    int days;
    int A[101];

    // Input reading
    scanf("%d %d %d", &N, &D, &X);

    // Reading values into array A
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Calculating the number of chocolates
=======
    /*
    1. Main function: The main function is defined to execute the program. It initializes variables and processes input to compute the number of chocolates needed.
    */
    int N, D, X;
    int num_of_chocolate;
    int counter;
    int days;
    int A[101];
    
    /*
    2. Input reading: The program reads three integers N, D, and X from the standard input.
    */
    scanf("%d %d %d", &N, &D, &X);
    
    /*
    3. Reading values into array A: The program reads N values into the array A.
    */
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    /*
    4. Calculating the number of chocolates: The program calculates the number of chocolates needed by iterating through each value in A and counting how many days it takes to consume all chocolates for each A[i].
    */
    num_of_chocolate = 0;
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < N; i++) {
        days = 0;
        counter = 0;
        for (int j = 0;; j++) {
            days = j * A[i] + 1;
            if (days <= D) {
                counter++;
<<<<<<< HEAD
            } else {
=======
            }
            else {
>>>>>>> 98c87cb78a (data updated)
                break;
            }
        }
        num_of_chocolate += counter;
    }
<<<<<<< HEAD

    // Adding extra chocolates
    num_of_chocolate += X;

    // Output the result
    printf("%d\n", num_of_chocolate);

    return 0;
}

// <END-OF-CODE>
=======
    
    /*
    5. Adding extra chocolates: The program adds the number of extra chocolates X to the total number of chocolates calculated.
    */
    num_of_chocolate += X;
    
    /*
    6. Output the result: Finally, the program prints the total number of chocolates to the standard output.
    */
    printf("%d\n", num_of_chocolate);
    
    return 0;
}

/* <END-OF-CODE> */
>>>>>>> 98c87cb78a (data updated)
