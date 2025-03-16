import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a scanner for input
        Scanner scanner = new Scanner(System.in);

        // Read height and width of the grid
        long h = scanner.nextLong();
        long w = scanner.nextLong();

        // Initialize the target string
        String target = "snuke";

        // Iterate through the grid to find the target string
        for (long i = 0; i < h; i++) {
            for (long j = 0; j < w; j++) {
                // Read the current string from input
                String current = scanner.next();

                // Check if the current string matches the target string
                if (current.equals(target)) {
                    // If found, calculate the position and print it
                    char c = (char) ('A' + j); // Convert column index to character
                    System.out.println(c + "" + (i + 1)); // Output the position in the required format
                    scanner.close(); // Close the scanner
                    return; // Exit the program after finding the target
                }
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
