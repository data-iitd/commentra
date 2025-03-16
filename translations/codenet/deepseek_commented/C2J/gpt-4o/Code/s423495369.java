import java.util.Scanner;  // Step 1: Import the Scanner class to read input from the user.

public class Main {  // Step 2: Define the main class.
    public static void main(String[] args) {  // Step 3: Define the main method where the execution of the program begins.
        Scanner scanner = new Scanner(System.in);  // Step 4: Create a Scanner object to read input.

        int A, B, C;  // Step 5: Declare three integer variables A, B, and C.

        A = scanner.nextInt();  // Step 6: Read the first integer from the user.
        B = scanner.nextInt();  // Step 7: Read the second integer from the user.
        C = scanner.nextInt();  // Step 8: Read the third integer from the user.

        // Step 9: Check if the value of C is between A and B using if-else statements.
        if (A < C && C < B) {  // Check if C is between A and B.
            System.out.println("Yes");  // Print "Yes" if the condition is true.
        } else if (A > C && C > B) {  // Check if C is between A and B in the opposite order.
            System.out.println("Yes");  // Print "Yes" if the condition is true.
        } else {
            System.out.println("No");  // Print "No" if the condition is false.
        }

        scanner.close();  // Step 10: Close the scanner to prevent resource leaks.
    }
}  // End of the Main class
// <END-OF-CODE>
