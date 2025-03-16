import java.util.ArrayList; // Importing ArrayList for dynamic array
import java.util.Collections; // Importing Collections for sorting
import java.util.Scanner; // Importing Scanner for input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read the number of strings 'N' and their lengths 'L' from the standard input
        long N = scanner.nextLong();
        long L = scanner.nextLong();

        // Initialize an ArrayList to store the strings
        ArrayList<String> v = new ArrayList<>();

        // Allocate memory for 'N' strings in the ArrayList 'v'
        for (long i = 0; i < N; i++) {
            // Read a string 's' from the standard input and add it to the ArrayList 'v'
            String s = scanner.next();
            v.add(s);
        }

        // Sort the strings in the ArrayList 'v' in ascending order
        Collections.sort(v);

        // Iterate through the sorted strings in the ArrayList 'v' and print each string
        for (String str : v) {
            // Print the current string from the ArrayList 'v'
            System.out.print(str);
        }

        // Print a newline character at the end of the output
        System.out.println();

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
