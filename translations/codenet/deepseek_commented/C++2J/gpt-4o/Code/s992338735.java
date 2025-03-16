import java.util.Scanner; // Import necessary classes

public class Main { // Define the main class
    public static void main(String[] args) { // Start the main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        while (true) { // Start an infinite loop
            int N = scanner.nextInt(); // Read the number of elements (N)
            if (N <= 0) break; // Exit the loop if N is not positive

            int M = -1; // Initialize maximum
            int m = 1001; // Initialize minimum
            int addup = 0; // Initialize sum

            for (int i = 0; i < N; i++) { // Loop through each element
                int S = scanner.nextInt(); // Read the element
                addup += S; // Add to the sum
                if (S > M) M = S; // Update maximum
                if (S < m) m = S; // Update minimum
            }
            // Calculate and print the average of the remaining numbers
            System.out.println((addup - M - m) / (N - 2)); 
        }
        scanner.close(); // Close the scanner
    } // End of main method
} // End of class Main
// <END-OF-CODE>
