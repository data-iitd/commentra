import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of players
        long k = scanner.nextLong(); // Initial points
        int q = scanner.nextInt(); // Number of queries
        int[] a = new int[q]; // Array to store query results
        int[] point = new int[100001]; // Array to store points for each player

        // Process each query to update points
        for (int i = 0; i < q; i++) {
            a[i] = scanner.nextInt();
            point[a[i] - 1]++; // Update points for the player who answered the query
        }

        // Determine if each player can reach the required points
        for (int i = 0; i < n; i++) {
            if (k - (q - point[i]) > 0) {
                System.out.println("Yes"); // Player can reach the required points
            } else {
                System.out.println("No"); // Player cannot reach the required points
            }
        }
    }
}
