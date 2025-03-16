import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking the number of points, n, and the number of dimensions, d, as input
        int n = scanner.nextInt();
        int d = scanner.nextInt();

        // Initializing a 2D array 'points' to store the coordinates of each point
        int[][] points = new int[n][d];

        // Filling the 'points' array with the coordinates of each point
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                points[i][j] = scanner.nextInt();
            }
        }

        // Defining a method 'dist' to calculate the Euclidean distance between two points
        double dist(int[] x, int[] y) {
            double tmp = 0.0;

            // Iterating through each dimension 'i' from 0 to 'd'
            for (int i = 0; i < d; i++) {
                // Adding the square of the difference between the 'i'th elements of 'x' and 'y' to 'tmp'
                tmp += Math.pow(x[i] - y[i], 2);
            }

            // Returning the square root of 'tmp' as the Euclidean distance between 'x' and 'y'
            return Math.sqrt(tmp);
        }

        // Initializing a variable 'count' to store the number of distinct pairs of points with integer distance
        int count = 0;

        // Iterating through each point 'i' in 'points'
        for (int i = 0; i < n; i++) {
            // Iterating through each point 'j' from 'i+1' to the last point in 'points'
            for (int j = i + 1; j < n; j++) {
                // Checking if the Euclidean distance between 'points[i]' and 'points[j]' is an integer
                if (Double.compare(dist(points[i], points[j]), (int) dist(points[i], points[j])) == 0) {
                    // Incrementing the 'count' variable if the condition is true
                    count++;
                }
            }
        }

        // Printing the final value of 'count'
        System.out.println(count);
    }
}
