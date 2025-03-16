import java.util.Scanner; // Import necessary classes

public class Main { // Define the main class
    public static void main(String[] args) { // Main method
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the number of heights
        int k = scanner.nextInt(); // Read the minimum height
        int cnt = 0; // Initialize the count variable

        while (n-- > 0) { // Use a while loop to read each height
            int h = scanner.nextInt(); // Read each height
            if (h >= k) // Check if the height is suitable
                cnt++; // Increment the count if the height is greater than or equal to k
        }
        
        System.out.println(cnt); // Print the final count
        scanner.close(); // Close the scanner
    } // End of main method
} // End of class
// <END-OF-CODE>
