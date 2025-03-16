import java.util.Scanner; // Step 1: Import the Scanner class for user input.

public class Main { // Step 2: Define the Main class.
    public static void main(String[] args) { // Step 3: Define the main method.
        int a, b, s; // Step 4: Declare three integer variables: a, b, and s.

        Scanner scanner = new Scanner(System.in); // Step 5: Create a Scanner object for input.
        a = scanner.nextInt(); // Step 6: Read the first integer from user input and store it in variable a.
        b = scanner.nextInt(); // Step 7: Read the second integer from user input and store it in variable b.

        s = (a * b) - (a + b) + 1; // Step 8: Calculate the value of s using the formula (a*b) - (a + b) + 1.

        System.out.println(s); // Step 9: Print the value of s.
        scanner.close(); // Step 10: Close the scanner to prevent resource leaks.
    }
} // End of the Main class
// <END-OF-CODE>
