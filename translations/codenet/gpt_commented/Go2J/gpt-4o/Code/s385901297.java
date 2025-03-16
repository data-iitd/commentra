import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new scanner to read input from standard input (stdin)
        Scanner scanner = new Scanner(System.in);

        // Initialize an array to hold four integers
        int[] ns = new int[4];

        // Read a line of input and parse it into the array
        for (int i = 0; i < 4; i++) {
            ns[i] = scanner.nextInt();
        }

        // Sort the array of integers in ascending order
        Arrays.sort(ns);

        // Check if the sorted integers match the specific sequence [1, 4, 7, 9]
        if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
            // If they match, print "YES"
            System.out.println("YES");
        } else {
            // If they do not match, print "NO"
            System.out.println("NO");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
