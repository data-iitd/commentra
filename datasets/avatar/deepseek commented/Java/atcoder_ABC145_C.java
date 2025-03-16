import java.util.Scanner; // Importing Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input
        int N = scanner.nextInt(); // Reading the number of points
        int[][] pos = new int[N][2]; // Initializing a 2D array to store coordinates

        // Reading coordinates of points
        for (int i = 0; i < N; i++) {
            pos[i][0] = scanner.nextInt(); // Reading x-coordinate
            pos[i][1] = scanner.nextInt(); // Reading y-coordinate
        }

        double sum = 0; // Initializing sum to store the total distance

        // Calculating the sum of distances between all pairs of points
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue; // Skipping the diagonal elements
                sum += dist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]); // Adding distance to sum
            }
        }

        // Calculating and printing the average distance
        System.out.println(sum / N);
    }

    // Helper function to calculate the Euclidean distance between two points
    private static double dist(int x1, int y1, int x2, int y2) {
        return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
}
