

import java.util.Scanner;

public class s860368733{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        int m = scanner.nextInt(); // Read the number of comparisons
        int[] h = new int[n]; // Create an array to store the heights of the elements
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt(); // Read the heights of the elements
        }
        int a, b; // Declare variables to store the indices of the elements being compared
        boolean[] counter = new boolean[n]; // Create an array to keep track of elements that cannot be the highest
        for (int i = 0; i < m; i++) {
            a = scanner.nextInt() - 1; // Read the first index of the comparison
            b = scanner.nextInt() - 1; // Read the second index of the comparison
            if (h[a] < h[b]) { // Check if the height of the first element is less than the second
                counter[a] = true; // Mark the first element as not being the highest
            } else if (h[a] > h[b]) { // Check if the height of the first element is greater than the second
                counter[b] = true; // Mark the second element as not being the highest
            } else if (h[a] == h[b]) { // Check if the heights of the two elements are equal
                counter[a] = true; // Mark both elements as not being the highest
                counter[b] = true;
            }
        }
        int count = 0; // Initialize a counter to keep track of the number of elements that cannot be the highest
        for (boolean c : counter) { // Iterate over the counter array
            if (!c) { // Check if the element is not marked as not being the highest
                count++; // Increment the counter
            }
        }
        System.out.println(count); // Print the number of elements that cannot be the highest
        scanner.close(); // Close the scanner
    }
}
