import java.util.Scanner; // Step 1: Import the Scanner class to read input from the user.

public class Main { // Step 2: Define the Main class.
    public static void main(String[] args) { // Step 3: Define the main method where the execution of the program begins.
        int a, b, c, d; // Step 4: Declare four integer variables a, b, c, and d to store the input values.
        
        Scanner scanner = new Scanner(System.in); // Step 5: Create a Scanner object to read input.
        a = scanner.nextInt(); // Step 6: Read the first integer from the user.
        b = scanner.nextInt(); // Step 7: Read the second integer from the user.
        c = scanner.nextInt(); // Step 8: Read the third integer from the user.
        d = scanner.nextInt(); // Step 9: Read the fourth integer from the user.

        if (a + b > c + d) // Step 10: Compare the sum of a and b with the sum of c and d.
            System.out.println("Left"); // Step 11: If the sum of a and b is greater than the sum of c and d, print "Left".
        else if (a + b < c + d) // Step 12: If the sum of a and b is less than the sum of c and d, print "Right".
            System.out.println("Right");
        else // Step 13: If the sums are equal, print "Balanced".
            System.out.println("Balanced");

        scanner.close(); // Step 14: Close the scanner to prevent resource leaks.
    } // End of main method.
} // End of Main class.
