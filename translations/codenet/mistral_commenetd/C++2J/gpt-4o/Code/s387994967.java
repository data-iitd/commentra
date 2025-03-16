import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int A, B; // Declare two integer variables A and B
        A = scanner.nextInt(); // Read the value of A from the standard input
        B = scanner.nextInt(); // Read the value of B from the standard input

        if (A < 13 && A >= 6) { // Check if A is within the range of 6 to 12 (inclusive)
            System.out.println(B / 2); // If true, divide B by 2 and print the result to the standard output
        }

        if (A < 6) { // Check if A is less than 6
            System.out.println(0); // If true, print 0 to the standard output
        }

        if (A >= 13) { // Check if A is greater than or equal to 13
            System.out.println(B); // If true, print B to the standard output
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
