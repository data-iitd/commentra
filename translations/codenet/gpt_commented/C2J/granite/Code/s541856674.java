
import java.util.Scanner;

public class s541856674{
    public static void main(String[] args) {
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Declare variables to hold the input values
        int N = 0; // Variable to store the first input value
        int R = 0; // Variable to store the second input value

        // Read two integers from user input
        N = scanner.nextInt();
        R = scanner.nextInt();

        // Check if the first input value N is greater than or equal to 10
        if(N >= 10) {
            // If N is 10 or more, print the value of R as is
            System.out.println(R);
        } else {
            // If N is less than 10, calculate and print R adjusted by the difference from 10
            System.out.println(R + 100 * (10 - N));
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
