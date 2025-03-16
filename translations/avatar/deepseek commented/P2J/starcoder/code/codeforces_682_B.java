import java.util.*;  // Importing the Java utilities library
import java.io.*;  // Importing the Java I/O library

public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        int n = Integer.parseInt(System.console().readLine());

        // Read the list of elements
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(System.console().readLine());
        }

        // Initialize variables
        int f = 1;  // Flag variable
        Arrays.sort(l);  // Sort the list
        int c = 0;  // Counter variable

        // Iterate through the list to find the maximum number of unique elements
        for (int i : l) {
            if (i > c) {
                c += 1;  // Increment the counter if the current element is greater than the counter
            }
        }

        // Print the result
        System.out.println(c + 1);  // Print the maximum number of unique elements
    }
}

