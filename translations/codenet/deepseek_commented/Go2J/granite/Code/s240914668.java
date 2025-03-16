
import java.io.*;
import java.util.*;

public class s240914668{
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in); // Initialize the scanner to read input words.
        int n = sc.nextInt(); // Read the number of elements n.
        int[] a = new int[n]; // Create an array a to store the integers.
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt(); // Read n integers into the array a.
        }

        int ans = 0; // Initialize ans to 0 to keep track of the number of segments.
        for (int i = 0; i < n; i++) {
            int l = i, r = i + 1; // Set l to i and r to i+1.
            while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
                r++; // Expand r as long as the condition holds.
            }
            ans++; // Increment ans after finding the segment.
            i = r; // Update i to r.
        }
        System.out.println(ans); // Output the number of segments ans.
        System.out.flush(); // Flush the output to ensure all data is written.
    }
}

