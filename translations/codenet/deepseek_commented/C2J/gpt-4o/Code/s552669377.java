import java.util.Scanner; // Import the Scanner class for input

public class Main { // Define the Main class
    public static void main(String[] args) { // Main method
        int n; // Declare number of elements
        long min = 1000000, max = -1000000, sum = 0; // Declare and initialize min, max, and sum

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        n = scanner.nextInt(); // Read the number of elements

        for (int i = 0; i < n; i++) { // Loop through the number of elements
            int tmp = scanner.nextInt(); // Read an integer value into tmp
            if (min > tmp) min = tmp; // Update min if tmp is smaller
            if (max < tmp) max = tmp; // Update max if tmp is larger
            sum += tmp; // Add tmp to sum
        }

        System.out.printf("%d %d %d\n", min, max, sum); // Print the results
        scanner.close(); // Close the scanner
    } // End of main method
} // End of Main class
// <END-OF-CODE>
