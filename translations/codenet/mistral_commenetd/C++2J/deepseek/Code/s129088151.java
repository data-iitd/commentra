import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Declare variables
    static int n;
    static char[] str = new char[10];
    static char[] com = new char[13];
    static Map<String, Boolean> T = new HashMap<>(); // A map to store strings as keys and boolean values

    public static void main(String[] args) {
        // Read the number of input pairs from the standard input
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        // Iterate through each input pair
        for (int i = 0; i < n; i++) {
            // Read the command and the string from the standard input
            com[0] = scanner.next().charAt(0);
            str = scanner.next().toCharArray();

            // If the command is 'i', add the string to the map with a value of true
            if (com[0] == 'i') {
                T.put(new String(str), true); // Set the value of the string as a key in the map to true
            }
            // If the command is not 'i', check if the string is present in the map and print the result accordingly
            else {
                if (T.containsKey(new String(str))) { // Check if the string is present in the map
                    System.out.println("yes"); // If present, print 'yes'
                } else {
                    System.out.println("no"); // If not present, print 'no'
                }
            }
        }
        // Return 0 to indicate successful execution of the program
    }
}
