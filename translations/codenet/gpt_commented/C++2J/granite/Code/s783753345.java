
import java.util.Scanner;

public class s783753345{
    public static void main(String[] args) {
        // Declare variables to hold two integers and a character for the operation
        int a, b;
        char S;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Start an infinite loop to continuously accept user input
        while (true) {
            // Read two integers and an operator from the user
            a = scanner.nextInt();
            S = scanner.next().charAt(0);
            b = scanner.nextInt();

            // Perform addition if the operator is '+'
            if (S == '+') 
                System.out.println(a + b);

            // Perform subtraction if the operator is '-'
            if (S == '-') 
                System.out.println(a - b);

            // Perform multiplication if the operator is '*'
            if (S == '*') 
                System.out.println(a * b);

            // Perform division if the operator is '/'
            if (S == '/') 
                System.out.println(a / b);

            // Exit the loop if the operator is '?'
            if (S == '?') 
                break;
        }

        // Close the Scanner object
        scanner.close();
    }
}
