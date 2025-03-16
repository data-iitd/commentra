
// Import necessary libraries
import java.util.*;
import java.io.*;

public class codeforces_682_B{
    public static void main(String[] args) throws IOException {
        // Initialize variables
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // Number of elements in the list
        String[] input = br.readLine().split(" "); // Read a line of integers
        int[] l = new int[n]; // List of integers from input
        int f = 1; // Starting count for unique elements
        int c = 0; // Counter for unique elements

        // Convert input strings to integers and sort the list
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(input[i]);
        }
        Arrays.sort(l);

        // Iterate through the sorted list to count unique elements
        for (int i = 0; i < n; i++) {
            if (l[i] > c) { // Check if the current element is greater than the counter
                c += 1; // Increment the counter for unique elements
            }
        }

        // Output the total count of unique elements
        System.out.println(c + 1); // Print the count of unique elements (including the first element)
    }
}
