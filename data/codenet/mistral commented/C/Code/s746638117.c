#include<stdio.h> // Including the standard input/output library

int main(){ // The main function is the starting point of the program
        int a, b, ar, le; // Declaring variables a, b, ar (result of multiplication), and le (result of addition and multiplication by 2)

        scanf("%d %d", &a, &b); // Reading two integers from the user and storing them in variables a and b

        ar = a * b; // Multiplying the values of variables a and b and storing the result in variable ar

        le = 2 * (a + b); // Multiplying the sum of variables a and b by 2 and storing the result in variable le

        printf("%d %d\n", ar, le); // Printing the values of variables ar and le to the console

        return 0; // Indicating that the program has run successfully
}
