import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a scanner for input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of strings (N) and the length of strings (L)
        int N = scanner.nextInt();
        int L = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Declare a list to store strings
        List<String> v = new ArrayList<>();

        // Input N strings from the user and store them in the list
        for (int i = 0; i < N; i++) {
            String s = scanner.nextLine();
            v.add(s); // Add the string to the list
        }

        // Sort the list of strings in lexicographical order
        Collections.sort(v);

        // Output the sorted strings
        for (String s : v) {
            System.out.print(s); // Print each string in the sorted order
        }
        System.out.println(); // Print a newline at the end

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
