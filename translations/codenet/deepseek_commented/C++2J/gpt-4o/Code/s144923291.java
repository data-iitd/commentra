import java.util.Scanner; // Import Scanner for input operations

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int h = scanner.nextInt(); // Read the height of the grid
        int w = scanner.nextInt(); // Read the width of the grid
        String target = "snuke"; // Define the target string
        boolean found = false; // Flag to check if the target is found

        for (int i = 0; i < h; i++) { // Loop over each row
            for (int j = 0; j < w; j++) { // Loop over each column
                String t = scanner.next(); // Read a string
                if (target.equals(t)) { // Compare the string with the target
                    char c = (char) ('A' + j); // Calculate the column letter
                    System.out.println(c + "" + (i + 1)); // Output the position in the grid
                    found = true; // Set the found flag to true
                    break; // Exit the inner loop
                }
            }
            if (found) break; // Exit the outer loop if found
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
