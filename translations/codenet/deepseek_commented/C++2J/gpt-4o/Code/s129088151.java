import java.util.HashMap; // Import the HashMap class for key-value pair storage
import java.util.Scanner; // Import the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n; // Declare an integer variable to store the number of operations
        n = scanner.nextInt(); // Read the number of operations from the user
        HashMap<String, Boolean> T = new HashMap<>(); // Declare a HashMap to store the presence of strings

        for (int i = 0; i < n; i++) { // Loop through each operation
            String command = scanner.next(); // Read the command
            String str = scanner.next(); // Read the string
            if (command.charAt(0) == 'i') { // If the command is 'i', insert the string into the map
                T.put(str, true);
            } else { // If the command is not 'i'
                if (T.getOrDefault(str, false)) { // Check if the string is present in the map
                    System.out.println("yes"); // Print 'yes' if present
                } else {
                    System.out.println("no"); // Print 'no' if not present
                }
            }
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
