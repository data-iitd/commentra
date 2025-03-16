import java.util.Scanner;

public class Main {
    // Method to calculate the Euclidean distance between two points
    public static double dist(int[] x, int[] y) {
        double tmp = 0.0;

        // Iterating through each dimension
        for (int i = 0; i < x.length; i++) {
            // Adding the square of the difference between the elements of x and y
            tmp += Math.pow(x[i] - y[i], 2);
        }

        // Returning the square root of tmp as the Euclidean distance
        return Math.sqrt(tmp);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking the number of points, n, and the number of dimensions, d, as input
        int n = scanner.nextInt();
        int d = scanner.nextInt();

        // Initializing an array to store the coordinates of each point
        int[][] points = new int[n][d];

        // Taking the coordinates of each point as input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                points[i][j] = scanner.nextInt();
            }
        }

        // Initializing a variable to store the number of distinct pairs of points with integer distance
        int count = 0;

        // Iterating through each point
        for (int i = 0; i < n; i++) {
            // Iterating through each point from i+1 to the last point
            for (int j = i + 1; j < n; j++) {
                // Checking if the Euclidean distance between points[i] and points[j] is an integer
                if (dist(points[i], points[j]) % 1 == 0) {
                    // Incrementing the count variable if the condition is true
                    count++;
                }
            }
        }

        // Printing the final value of count
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
