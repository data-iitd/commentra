
import java.util.Scanner;

public class s001352307{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t;

        // Infinite loop to process multiple test cases
        for(t = 0; ; t++) {
            int W, N;
            int[][] ans = new int[1024][2];
            int[][] input = new int[1024][2];

            // Initialize the ans and input arrays to zero for each test case
            for(int i = 0; i < 1024; i++) {
                ans[i][0] = 0; // Maximum value for capacity i
                ans[i][1] = 0; // Total weight for maximum value
                input[i][0] = 0; // Value of item i
                input[i][1] = 0; // Weight of item i
            }

            // Read the weight limit (W) and number of items (N)
            W = scanner.nextInt();
            N = scanner.nextInt();
            // Break the loop if the weight limit is zero (end of input)
            if(W == 0)
                break;

            // Read the value and weight of each item
            for(int i = 0; i < N; i++) {
                String[] inputStr = scanner.next().split(",");
                input[i][0] = Integer.parseInt(inputStr[0]); // Value of item i
                input[i][1] = Integer.parseInt(inputStr[1]); // Weight of item i
            }

            // Dynamic programming to calculate the maximum value for each capacity
            for(int i = 0; i < N; i++) {
                // Traverse the capacities in reverse to avoid overwriting results
                for(int j = 1023; j >= input[i][1]; j--) {
                    // Check if including the current item increases the maximum value
                    if(ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
                        // Update the maximum value and corresponding weight
                        ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
                        ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
                    }
                }
            }

            // Find the maximum value and corresponding weight for the exact weight limit
            int j;
            for(j = 0; ans[W][0] == ans[W - j - 1][0]; j++);

            // Print the results for the current test case
            System.out.println("Case " + (t + 1) + ":");
            System.out.println(ans[W - j][0]);
            System.out.println(ans[W - j][1]);
        }
    }
}

