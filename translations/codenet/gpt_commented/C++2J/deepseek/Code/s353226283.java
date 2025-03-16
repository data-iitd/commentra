import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    // Declare global variables
    static int n, k; // n: number of elements, k: size of the subset
    static ArrayList<Integer> vec = new ArrayList<>(); // ArrayList to store the input elements
    static int ans = 1000000001; // Initialize ans to a large value to find the minimum difference

    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements (n) and the size of the subset (k)
        n = scanner.nextInt();
        k = scanner.nextInt();

        // Read n integers from input and store them in the ArrayList
        for (int i = 0; i < n; i++) {
            int t = scanner.nextInt(); // Read each integer
            vec.add(t); // Add the integer to the ArrayList
        }

        // Sort the ArrayList in non-decreasing order
        Collections.sort(vec);

        // Iterate through the sorted ArrayList to find the minimum difference
        for (int i = 0; i + k - 1 < n; i++) {
            // Calculate the difference between the maximum and minimum of the current subset of size k
            int diff = vec.get(i + k - 1) - vec.get(i);
            
            // Update the minimum difference found so far
            if (diff < ans) {
                ans = diff; // Update ans if a smaller difference is found
            }
        }

        // Output the minimum difference found
        System.out.println(ans);
    }
}
