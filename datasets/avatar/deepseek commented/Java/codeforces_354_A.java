import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Creating a Scanner object to read input
        int N = in.nextInt(); // Reading the number of items
        int L = in.nextInt(); // Reading the cost coefficient for items
        int R = in.nextInt(); // Reading the cost coefficient for items
        int QL = in.nextInt(); // Reading the cost coefficient for unbalanced left count
        int QR = in.nextInt(); // Reading the cost coefficient for unbalanced right count
        int[] W = new int[N]; // Array to store the weights of items
        int[] sum = new int[N + 1]; // Array to store cumulative sums of weights

        // Reading the weights and calculating cumulative sums
        for (int n = 0; n < N; n++) {
            W[n] = in.nextInt();
            sum[n + 1] = sum[n] + W[n];
        }

        // Initializing the minimum cost to a very large value
        long min = Long.MAX_VALUE;

        // Iterating over possible positions for the rightmost item
        for (int firstR = 0; firstR <= N; firstR++) {
            int lCount = firstR; // Number of items on the left
            int rCount = N - lCount; // Number of items on the right

            // Calculating the cost for the current position of the rightmost item
            long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;

            // Calculating the additional costs for unbalanced counts
            int llCount = Math.max(0, lCount - rCount - 1);
            int rrCount = Math.max(0, rCount - lCount - 1);
            cand += llCount * QL;
            cand += rrCount * QR;

            // Updating the minimum cost found so far
            min = Math.min(cand, min);
        }

        // Printing the minimum cost
        System.out.println(min);
    }
}