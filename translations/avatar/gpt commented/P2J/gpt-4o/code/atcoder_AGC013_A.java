import java.util.*;
import java.io.*;

public class Main {
    // Define a constant for infinity
    static final double INF = Double.POSITIVE_INFINITY;

    // Define a constant for the modulo value
    static final int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Read the number of elements
        int N = Integer.parseInt(br.readLine().trim());

        // Read the list of integers
        String[] input = br.readLine().trim().split(" ");
        List<Integer> A = new ArrayList<>();
        for (String s : input) {
            A.add(Integer.parseInt(s));
        }

        // Remove consecutive duplicates from the list
        List<Integer> uniqueA = new ArrayList<>();
        for (int i = 0; i < A.size(); i++) {
            if (i == 0 || !A.get(i).equals(A.get(i - 1))) {
                uniqueA.add(A.get(i));
            }
        }

        // Update N to the new length of uniqueA after removing duplicates
        N = uniqueA.size();
        A = uniqueA;

        // Initialize the index and answer counter
        int i = 1;
        int ans = 0;

        // Loop through the list to count the number of peaks and valleys
        while (i < N - 1) {
            // Check if the current element is a peak or a valley
            if ((A.get(i - 1) < A.get(i) && A.get(i) > A.get(i + 1)) || 
                (A.get(i - 1) > A.get(i) && A.get(i) < A.get(i + 1))) {
                ans++;  // Increment the answer for each peak/valley found
                i++;    // Skip the next element to avoid double counting
            }
            i++;  // Move to the next element
        }

        // Print the total count of peaks and valleys plus one
        System.out.println(ans + 1);
    }
}
// <END-OF-CODE>
