import java.util.Scanner; // Import the Scanner class for reading user input
import java.util.stream.IntStream; // Import IntStream for range-based operations

public class Main {
    private static final int MAX = 100; // Define a constant MAX for the maximum value

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) { // Initialize a Scanner object to read input
            int n = scanner.nextInt(); // Read the number of points from the user input
            int[] x = new int[n], y = new int[n], h = new int[n]; // Initialize arrays to store coordinates and heights

            // Read the coordinates and heights of each point from the user input
            IntStream.range(0, n).forEach(i -> {
                x[i] = scanner.nextInt();
                y[i] = scanner.nextInt();
                h[i] = scanner.nextInt();
            });

            // Iterate over a range of possible coordinates (i, j) up to MAX
            for (int i = 0; i <= MAX; i++) {
                for (int j = 0; j <= MAX; j++) {
                    int ch = check(n, x, y, h, i, j); // Call the check function to determine if it is a valid center
                    if (ch > 0) { // If the check function returns a valid height
                        System.out.println(i + " " + j + " " + ch); // Print the center coordinates and height
                    }
                }
            }
        }
    }

    // Check function to determine if a point (cx, cy) is a valid center
    private static int check(int n, int[] x, int[] y, int[] h, int cx, int cy) {
        int ch = -1; // Initialize ch to -1
        for (int i = 0; i < n; i++) { // Loop through each point
            if (h[i] > 0) { // If the height of the point is greater than 0
                ch = Math.abs(x[i] - cx) + Math.abs(y[i] - cy) + h[i]; // Calculate the height difference
                break; // Break the loop as we found a valid height
            }
        }

        // Verify if the calculated height matches the height of all points
        for (int i = 0; i < n; i++) {
            if (h[i] != Math.max(ch - Math.abs(x[i] - cx) - Math.abs(y[i] - cy), 0)) {
                return -1; // If any point does not match, return -1
            }
        }
        return ch; // Return the calculated height if all points match
    }
}
