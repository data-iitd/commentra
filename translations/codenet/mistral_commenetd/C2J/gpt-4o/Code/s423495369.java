import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three integer variables A, B, and C
        int A, B, C;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read three integers from the standard input
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();

        // Check if A is less than C and C is less than B
        if (A < C && C < B) {
            // If condition is true, print "Yes" to the standard output
            System.out.println("Yes");
        } // End of first if block

        // Else if condition checks if A is greater than C and C is greater than B
        else if (A > C && C > B) {
            // If condition is true, print "Yes" to the standard output
            System.out.println("Yes");
        } // End of second if block

        // Else condition is executed when neither first nor second condition is true
        else {
            // If condition is false, print "No" to the standard output
            System.out.println("No");
        } // End of else block

        // Close the scanner
        scanner.close();
    } // End of main function
} // End of class Main
// <END-OF-CODE>
