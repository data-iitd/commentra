
import java.io.*;
import java.util.*;

public class s240914668{
    public static void main(String[] args) throws IOException {
        // Set the scanner to split input by whitespace
        Scanner sc = new Scanner(System.in);

        // Read the number of integers
        int n = sc.nextInt();
        // Read the integers into a list
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }

        // Initialize the answer counter
        int ans = 0;

        // Iterate through the list of integers
        for (int i = 0; i < n; i++) {
            // Set the left and right pointers for the current segment
            int l = i, r = i + 1;

            // Expand the right pointer while the conditions are met
            while (r + 1 < n && (a.get(r) - a.get(l)) * (a.get(r + 1) - a.get(r)) >= 0) {
                r++;
            }

            // Increment the answer for each segment found
            ans++;
            // Move the left pointer to the end of the current segment
            i = r;
        }

        // Output the final count of segments
        System.out.println(ans);
        // Flush the buffered writer to ensure all output is written
        System.out.flush();
    }
}

