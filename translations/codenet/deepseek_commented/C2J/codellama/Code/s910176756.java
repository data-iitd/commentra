// Include the standard input-output library
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables to store the operands and the result
        int a, b, c;
        // Declare a character variable to store the operator
        char op;
        // Read two integers and an operator from the user
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        op = sc.next().charAt(0);
        b = sc.nextInt();
        while (true) { // Start an infinite loop
            if (op == '+') { // Check if the operator is addition
                c = a + b; // Perform the addition operation
                System.out.println(c); // Print the result
            } else if (op == '-') { // Check if the operator is subtraction
                c = a - b; // Perform the subtraction operation
                System.out.println(c); // Print the result
            } else if (op == '*') { // Check if the operator is multiplication
                c = a * b; // Perform the multiplication operation
                System.out.println(c); // Print the result
            } else if (op == '/') { // Check if the operator is division
                c = a / b; // Perform the division operation
                System.out.println(c); // Print the result
            } else { // If the operator is not recognized
                break; // Exit the loop and end the program
            }
            a = sc.nextInt(); // Read the next set of operands and operator
            op = sc.next().charAt(0);
            b = sc.nextInt();
        }
    }
}

