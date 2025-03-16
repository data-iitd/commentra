import java.util.Scanner;

public class IntegerDistancePairs {
    // Define a function to calculate the Euclidean distance between two points
    public static double dist(int[] x, int[] y) {
        double tmp = 0.0;
        for (int i = 0; i < x.length; i++) {
            tmp += Math.pow(x[i] - y[i], 2);
        }
        return Math.sqrt(tmp);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of points and the dimension from the input
        int n = scanner.nextInt();
        int d = scanner.nextInt();

        // Read n points, each with d coordinates, and store them in an array
        int[][] points = new int[n][d];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                points[i][j] = scanner.nextInt();
            }
        }

        // Initialize a counter to keep track of pairs with integer distances
        int count = 0;

        // Iterate over all pairs of points
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Check if the distance between the two points is an integer
                if (dist(points[i], points[j]) % 1 == 0) {
                    count++;
                }
            }
        }

        // Print the total count of pairs with integer distances
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
