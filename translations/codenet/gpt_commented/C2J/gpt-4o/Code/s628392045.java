import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n; // n: number of elements
        int max = -1; // Variable to track the maximum height
        int flag = 0; // Flag to indicate if the condition is met

        // Create a scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        n = scanner.nextInt();
        int[] h = new int[n]; // Array to store heights

        // Loop to read heights and determine the maximum height
        for (int i = 0; i < n; i++) {
            // Read height into the array
            h[i] = scanner.nextInt();

            // Update maximum height if current height is greater
            if (max < h[i]) max = h[i];

            // Check if the difference between max height and current height is 2 or more
            if (max - h[i] >= 2) flag = 1; // Set flag if condition is met
        }

        // Output result based on the flag value
        if (flag == 1) 
            System.out.println("No"); // If flag is set, print "No"
        else 
            System.out.println("Yes"); // If flag is not set, print "Yes"

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
