
import java.util.*;
// Include the standard input output library

public class Main{
// Declare the main class

public static void main(String[] args){
// Declare the main function

Scanner input = new Scanner(System.in);
// Create a new Scanner object and store it in the variable input

int a,b,c,d,i,j;
// Declare variables a, b, c, d, i, and j

a = input.nextInt();
// Read an integer from the standard input and store it in variable a

b = input.nextInt();
// Read an integer from the standard input and store it in variable b

c = input.nextInt();
// Read an integer from the standard input and store it in variable c

d = input.nextInt();
// Read an integer from the standard input and store it in variable d

i = a*b;
// Multiply variables a and b and store the result in variable i

j = c*d;
// Multiply variables c and d and store the result in variable j

if(i>j){
// Check if the value of i is greater than j

    System.out.println(i);
// If true, print the value of i

}
else{
// If the condition in the if statement is false

    System.out.println(j);
// Print the value of j
}

}
}

