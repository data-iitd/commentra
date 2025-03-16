import java.util.Scanner;

public class TripletCounter {
    public static void main(String[] args) {
        // Optimize input/output operations
        Scanner scanner = new Scanner(System.in);

        int n; // Variable to store the number of elements
        n = scanner.nextInt(); // Read the number of elements from input

        int[] p = new int[n]; // Declare an array to hold the elements
        for (int i = 0; i < n; i++) 
            p[i] = scanner.nextInt(); // Read the elements into the array

        int ans = 0; // Initialize a counter for the number of valid triplets
        // Loop through the array to check for increasing or decreasing triplets
        for (int i = 0; i < n - 2; i++) {
            // Check if the current triplet is strictly decreasing
            if (p[i] > p[i + 1] && p[i + 1] > p[i + 2]) 
                ans++; // Increment the counter for decreasing triplet

            // Check if the current triplet is strictly increasing
            if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) 
                ans++; // Increment the counter for increasing triplet
        }

        System.out.println(ans); // Output the total count of valid triplets
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
