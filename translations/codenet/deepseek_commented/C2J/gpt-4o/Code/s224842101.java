import java.util.Scanner; // Step 1: Import necessary classes

public class Main { // Step 2: Define the main class
    public static void main(String[] args) { // Step 3: Define the main method
        int i, a, b, s; // Step 4: Declare necessary variables
        int[] count = new int[4]; // Declare an array to store the count of connections for each node

        for (i = 0; i < 4; i++) count[i] = 0; // Step 5: Initialize the count array

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        for (i = 0; i < 3; i++) { // Step 6: Read input values and update the count array
            a = scanner.nextInt();
            b = scanner.nextInt();
            count[a - 1]++; // Increment the count for node a
            count[b - 1]++; // Increment the count for node b
        }

        s = 1; // Initialize s to 1
        for (i = 0; i < 4; i++) s *= count[i]; // Step 7: Calculate the product of the counts

        if (s == 4) System.out.println("YES"); // Step 8: Check if the product is 4 and print the result
        else System.out.println("NO");

        scanner.close(); // Close the scanner
    } // End of main method
} // End of class Main
// <END-OF-CODE>
