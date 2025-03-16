
import java.util.*;
import java.io.*;

public class s765257696{
    public static void main(String[] args) throws IOException {
        // Optimize input/output operations
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine()); // Read the number of elements from input

        int[] p = new int[n]; // Declare an array to hold the elements
        String[] inputs = br.readLine().split(" "); // Read the elements into the array
        for (int i = 0; i < n; i++) 
            p[i] = Integer.parseInt(inputs[i]);

        int ans = 0; // Initialize a counter for the number of valid triplets
        // Loop through the array to check for increasing or decreasing triplets
        for (int i = 0; i < n - 2; i++) {
            // Check if the current triplet is strictly decreasing
            if (p[i] > p[i+1] && p[i+1] > p[i+2]) 
                ans++; // Increment the counter for decreasing triplet

            // Check if the current triplet is strictly increasing
            if (p[i] < p[i+1] && p[i+1] < p[i+2]) 
                ans++; // Increment the counter for increasing triplet
        }

        bw.write(Integer.toString(ans)); // Output the total count of valid triplets
        bw.newLine(); // Add a new line to the output
        bw.flush(); // Flush the output buffer

        br.close(); // Close the input stream
        bw.close(); // Close the output stream
    }
}

