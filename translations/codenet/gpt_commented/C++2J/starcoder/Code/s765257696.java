import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Optimize input/output operations
        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n; // Variable to store the number of elements
        n = sc.nextInt(); // Read the number of elements from input

        int p[] = new int[n]; // Declare an array to hold the elements
        for (int i = 0; i < n; i++) 
            p[i] = sc.nextInt(); // Read the elements into the array

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

        bw.write(ans + "\n"); // Output the total count of valid triplets
        bw.close();
        sc.close();
    }
}

