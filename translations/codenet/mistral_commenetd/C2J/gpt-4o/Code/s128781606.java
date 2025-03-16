import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // The entry point of the program
        int A, B, C, D, E, max; // Declare variables A, B, C, D, E, and max

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        A = scanner.nextInt(); // Read the first integer and store it in A
        B = scanner.nextInt(); // Read the second integer and store it in B

        C = A + B; // Compute the sum of A and B and store the result in C
        D = A - B; // Compute the difference of A and B and store the result in D
        E = A * B; // Compute the product of A and B and store the result in E

        max = C; // Initialize max with the value of C

        if (max < D) { // Check if D is greater than max
            max = D; // If so, update max with the value of D
        }

        if (max < E) { // Check if E is greater than max
            max = E; // If so, update max with the value of E
        }

        System.out.println(max); // Print the maximum value to the standard output

        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
