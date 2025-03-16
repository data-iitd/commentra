import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of people
        long k = scanner.nextLong(); // Total points
        int q = scanner.nextInt(); // Number of queries
        int[] a = new int[q]; // Array to store the query numbers
        int[] point = new int[n]; // Array to store the current points for each person

        // Distribute the points to each query one by one
        for (int i = 0; i < q; i++) {
            a[i] = scanner.nextInt(); // Read the query number
            point[a[i] - 1]++; // Increase the points for the person with the query number
        }

        // Check if it's possible to distribute the remaining points to the remaining people
        for (int i = 0; i < n; i++) {
            if (k - (q - point[i]) > 0) { // If the remaining points are greater than the difference between the total points and the points already distributed
                System.out.println("Yes"); // It's possible to distribute the remaining points to the remaining people
            } else {
                System.out.println("No"); // It's impossible to distribute the remaining points to the remaining people
            }
        }
    }
}
