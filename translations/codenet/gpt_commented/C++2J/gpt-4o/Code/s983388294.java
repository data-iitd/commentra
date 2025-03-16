import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        // Create a scanner to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int n = scanner.nextInt();

        // Initialize an ArrayList to store the input elements
        ArrayList<Integer> a = new ArrayList<>(n);

        // Read n integers into the ArrayList
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }

        // Initialize a counter for the current expected number
        int curr = 0;

        // Iterate through the ArrayList to find the longest prefix of consecutive integers starting from 1
        for (int i = 0; i < n; i++) {
            if (a.get(i) == curr + 1) {
                curr++; // Increment curr if the current element matches the expected value
            }
        }

        // Check if any consecutive integers were found
        if (curr > 0) {
            // Print the number of elements not in the consecutive sequence
            System.out.println(n - curr);
        } else {
            // If no consecutive integers were found, print -1
            System.out.println("-1");
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
