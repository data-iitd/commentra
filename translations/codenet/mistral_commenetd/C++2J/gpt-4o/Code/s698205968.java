import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int m, f, r; // Declare variables m, f, and r to store user input

        while (scanner.hasNextInt()) { // Start of the while loop
            m = scanner.nextInt(); // Read the first integer
            f = scanner.nextInt(); // Read the second integer
            r = scanner.nextInt(); // Read the third integer

            if (m == -1 || f == -1) { // Check if m or f is -1
                System.out.println("F"); // If so, print "F" and move on to the next input
                continue;
            }

            if (m + f >= 80) { // Check if the sum of m and f is greater than or equal to 80
                System.out.println("A"); // If so, print "A" and move on to the next input
                continue;
            }

            if (m + f >= 65) { // Check if the sum of m and f is greater than or equal to 65
                System.out.println("B"); // If so, print "B" and move on to the next input
                continue;
            }

            if (m + f >= 50 || r >= 50) { // Check if the sum of m and f is greater than or equal to 50
                                            // or if r is greater than or equal to 50
                System.out.println("C"); // If so, print "C" and move on to the next input
                continue;
            }

            if (m + f >= 30) { // Check if the sum of m and f is greater than or equal to 30
                System.out.println("D"); // If so, print "D" and move on to the next input
                continue;
            }

            System.out.println("F"); // If none of the above conditions are met, print "F" and move on to the next input
        }

        scanner.close(); // Close the scanner to free resources
    }
} // End of the Main class
// <END-OF-CODE>
