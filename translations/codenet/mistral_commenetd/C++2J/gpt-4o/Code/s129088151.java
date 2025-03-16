import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n;
        String str, com;
        Map<String, Boolean> T = new HashMap<>(); // A map to store strings as keys and boolean values

        // Read the number of input pairs from the standard input
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Iterate through each input pair
        for (int i = 0; i < n; i++) {
            // Read the command and the string from the standard input
            com = scanner.next();
            str = scanner.next();

            // If the command is 'i', add the string to the map with a value of true
            if (com.charAt(0) == 'i') {
                T.put(str, true); // Set the value of the string as a key in the map to true
            } 
            // If the command is not 'i', check if the string is present in the map and print the result accordingly
            else {
                if (T.containsKey(str)) { // Check if the string is present in the map
                    System.out.println("yes"); // If present, print 'yes'
                } else {
                    System.out.println("no"); // If not present, print 'no'
                }
            }
        }
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
