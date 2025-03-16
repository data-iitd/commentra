import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for input and a map to store string entries
        int n; // Number of commands to process
        String str; // String to hold the input string
        String com; // String to hold the command input
        Map<String, Boolean> T = new HashMap<>(); // Map to track the presence of strings (true if present)

        // Read the number of commands from input
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Loop through each command
        for (int i = 0; i < n; i++) {
            // Read the command and the associated string
            com = scanner.next();
            str = scanner.next();

            // Check if the command is 'insert' (indicated by the first character being 'i')
            if (com.charAt(0) == 'i') {
                // Insert the string into the map with a value of true
                T.put(str, true);
            } else {
                // If the command is not 'insert', check if the string exists in the map
                if (T.containsKey(str) && T.get(str)) {
                    // If the string exists, print "yes"
                    System.out.println("yes");
                } else {
                    // If the string does not exist, print "no"
                    System.out.println("no");
                }
            }
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
