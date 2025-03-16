
import java.util.Scanner;
import java.util.HashMap;

public class s129088151{
    public static void main(String[] args) {
        // Declare variables for input and a map to store string entries
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of commands to process
        String str, com; // Variables to hold command and string inputs
        HashMap<String, Boolean> T = new HashMap<>(); // Map to track the presence of strings (true if present)

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
                if (T.containsKey(str)) {
                    // If the string exists, print "yes"
                    System.out.println("yes");
                } else {
                    // If the string does not exist, print "no"
                    System.out.println("no");
                }
            }
        }
        
        // Return 0 to indicate successful execution
        System.out.println("