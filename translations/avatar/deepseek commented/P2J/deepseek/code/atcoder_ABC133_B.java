import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of points and the dimension from the input
        int n = scanner.nextInt();
        int d = scanner.nextInt();

        // Read n points, each with d coordinates, and store them in a 2D array called points
        double[][] points = new double[n][d];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                points[i][j] = scanner.nextDouble();
            }
        }

        // Initialize a counter to keep track of pairs with integer distances
        int count = 0;

        // Iterate over all pairs of points
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Calculate the Euclidean distance between the two points
                double distance = calculateDistance(points[i], points[j], d);

                // Check if the distance is an integer
                if (isInteger(distance)) {
                    count++;
                }
            }
        }

        // Print the total count of pairs with integer distances
        System.out.println(count);
    }

    // Define a method to calculate the Euclidean distance between two points
    public static double calculateDistance(double[] x, double[] y, int d) {
        double tmp = 0.0;
        for (int i = 0; i < d; i++) {
            tmp += Math.pow(x[i] - y[i], 2);
        }
        return Math.sqrt(tmp);
    }

    // Define a method to check if a number is an integer
    public static boolean isInteger(double num) {
        return num == (int) num;
    }
}
