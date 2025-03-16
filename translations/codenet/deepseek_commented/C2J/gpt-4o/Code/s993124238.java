import java.util.Scanner;  // Import Scanner class for input operations
import java.lang.Math;     // Import Math class for mathematical functions

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int n = scanner.nextInt();  // Read the number of points
        int d = scanner.nextInt();  // Read the number of dimensions
        
        int[][] point = new int[n + 1][d + 1];  // Declare a 2D array to store the points
        
        // Nested loop to read the coordinates of each point
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= d; j++) {
                point[i][j] = scanner.nextInt();  // Read each coordinate
            }
        }
        
        int count = 0;  // Initialize a counter to zero to count the number of integer distances
        
        // Nested loop to calculate the Euclidean distance between each pair of points
        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sum = 0;  // Initialize a variable to store the sum of squared differences
                for (int k = 1; k <= d; k++) {
                    sum += (point[i][k] - point[j][k]) * (point[i][k] - point[j][k]);  // Calculate squared difference
                }
                double kyori = Math.sqrt(sum);  // Compute the square root of the sum to get the distance
                
                // Check if the distance is an integer by comparing ceil and floor of the distance
                if (Math.ceil(kyori) == Math.floor(kyori)) {
                    count++;  // Increment the counter if the distance is an integer
                }
            }
        }
        
        System.out.println(count);  // Print the final count of integer distances
    }
}
// <END-OF-CODE>
