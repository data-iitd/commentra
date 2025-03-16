import java.util.Scanner;

public class IntegerDistancePairs {
    
    // Define a method to calculate the Euclidean distance between two points
    public static double dist(int[] x, int[] y) {
        double tmp = 0.0;
        // Calculate the squared differences for each dimension
        for (int i = 0; i < x.length; i++) {
            tmp += Math.pow(x[i] - y[i], 2);
        }
        // Return the square root of the sum of squared differences
        return Math.sqrt(tmp);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of points (n) and the dimension (d) from input
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        // Read the coordinates of the points into an array
        int[][] points = new int[n][d];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                points[i][j] = scanner.nextInt();
            }
        }
        
        // Initialize a counter for pairs of points with integer distances
        int count = 0;

        // Iterate through each point and compare it with every other point
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Check if the distance between the two points is an integer
                if (dist(points[i], points[j]) % 1 == 0) {
                    count++;  // Increment the count if the distance is an integer
                }
            }
        }

        // Print the total count of pairs with integer distances
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
