import java.util.Scanner; // Import Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n; // Declare variable for number of elements
        int max = -1; // Initialize max to -1 to store the maximum height found
        int flag = 0; // Initialize flag to 0 to indicate whether the condition is met

        n = scanner.nextInt(); // Read the number of elements from the standard input
        int[] h = new int[n]; // Declare an array to store heights of elements

        // Loop to read heights and update the maximum height found
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt(); // Read the height of the i-th element
            if (max < h[i]) max = h[i]; // Update max if the current height is greater than max

            if (max - h[i] >= 2) flag = 1; // Check if the difference between max and current height is at least 2
        }

        if (flag == 1) System.out.println("No"); // Print "No" if the condition is met
        else System.out.println("Yes"); // Print "Yes" if the condition is not met

        scanner.close(); // Close the scanner to free resources
    }
}
// <END-OF-CODE>
