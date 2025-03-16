import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the Main class
    public static void main(String[] args) { // Beginning of the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int m, f, r; // Declare variables m, f, and r to store user input

        while (scanner.hasNextInt()) { // Start of the while loop
            // The loop continues as long as the user inputs valid integers (m, f, and r)
            // and at least one of them is not -1

            m = scanner.nextInt(); // Read the next integer input for m
            f = scanner.nextInt(); // Read the next integer input for f
            r = scanner.nextInt(); // Read the next integer input for r

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

        scanner.close(); // Close the Scanner object to free up resources
    }
}
