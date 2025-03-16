import java.util.Scanner;

public class Main {
    // Define constants W and N for the width and number of blocks respectively
    static int W, N;

    // Define a 2D array input to store the dimensions of each block
    static int[][] input = new int[1024][2];

    // Define a 2D array ans to store the maximum size of a rectangle that can be formed by placing a block of given size at each position
    static int[][] ans = new int[1024][2];

    public static void main(String[] args) {
        // Initialize variables i, j, t, and arrays ans and input
        int i, j, t;

        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Loop through all test cases
        for(t = 0; ; t++) {
            // Initialize all elements of arrays ans and input to zero
            for(i = 0; i < 1024; i++) {
                ans[i][0] = 0;
                ans[i][1] = 0;
                input[i][0] = 0;
                input[i][1] = 0;
            }

            // Read the width W and number of blocks N from the input
            W = scanner.nextInt();
            N = scanner.nextInt();

            // If width W is zero, break out of the loop and move on to the next test case
            if(W == 0)
                break;

            // Read the dimensions of each block and store them in the input array
            for(i = 0; i < N; i++) {
                String[] dimensions = scanner.next().split(",");
                input[i][0] = Integer.parseInt(dimensions[0]);
                input[i][1] = Integer.parseInt(dimensions[1]);
            }

            // For each position j from the width W down to 0, update the maximum size of a rectangle that can be formed by placing a block of given size at that position
            for(i = 0; i < N; i++) {
                for(j = W; j >= input[i][1]; j--) {
                    // If the maximum size of a rectangle that can be formed by placing a block of size input[i] at position j - input[i][1] is less than the sum of the size of the current block and the maximum size of a rectangle at position j - input[i][1], update the maximum size of a rectangle at position j
                    if(ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
                        ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
                        ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
                    }
                }
            }

            // Find the position j such that the maximum size of a rectangle at position W - j is greater than the maximum size of a rectangle at position W - j - 1
            for(j = 0; j <= W; j++)
                if(ans[W - j][0] > ans[W - j - 1][0])
                    break;

            // Print the result for the current test case
            System.out.println("Case " + (t + 1) + ":");
            System.out.println(ans[W - j][0]);
            System.out.println(ans[W - j][1]);
        }

        // Close the Scanner object
        scanner.close();
    }
}

