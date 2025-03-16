import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] vec = new int[n];
        int ans = 1000000001; // Initialize the answer with a large number
        for (int i = 0; i < n; i++) {
            vec[i] = sc.nextInt();
        }
        Arrays.sort(vec); // Sort the vector in ascending order
        for (int i = 0; i + k - 1 < n; i++) { // Iterate through the sorted vector
            int diff = vec[i + k - 1] - vec[i]; // Calculate the difference between the max and min in the subarray
            if (diff < ans) { // Update the answer if the current difference is smaller
                ans = diff;
            }
        }
        System.out.println(ans); // Output the minimum difference
    }
}

