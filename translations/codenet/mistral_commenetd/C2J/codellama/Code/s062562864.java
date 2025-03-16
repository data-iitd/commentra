
import java.util.Scanner;
// Import the Scanner class

public class Main {
// Declare the Main class

    public static void main(String[] args) {
// Declare the main function

        Scanner sc = new Scanner(System.in);
// Declare a Scanner object sc

        int a = sc.nextInt();
// Read an integer from the standard input and store it in variable a

        int b = sc.nextInt();
// Read an integer from the standard input and store it in variable b

        int c = sc.nextInt();
// Read an integer from the standard input and store it in variable c

        int d = sc.nextInt();
// Read an integer from the standard input and store it in variable d

        int i = a * b;
// Multiply variables a and b and store the result in variable i

        int j = c * d;
// Multiply variables c and d and store the result in variable j

        if (i > j) {
// Check if the value of i is greater than j

            System.out.println(i);
// If true, print the value of i

        } else {
// If the condition in the if statement is false

            System.out.println(j);
// Print the value of j
        }

    }

}

