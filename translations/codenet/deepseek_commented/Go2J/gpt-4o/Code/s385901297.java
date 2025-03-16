import java.util.Arrays; // Importing the Arrays class for array operations
import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new scanner to read from standard input

        int[] ns = new int[4]; // Create an array of integers with a length of 4
        for (int i = 0; i < 4; i++) {
            ns[i] = scanner.nextInt(); // Read four integers from the input and store them in the array ns
        }

        Arrays.sort(ns); // Sort the array ns in ascending order
        if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) { // Check if the sorted array ns contains the numbers 1, 4, 7, and 9 in that order
            System.out.println("YES"); // Print "YES" if the condition is true
        } else {
            System.out.println("NO"); // Print "NO" if the condition is false
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
