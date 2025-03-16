import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of intervals
        int t = scanner.nextInt(); // Read the time range
        int[] mem = new int[100001]; // Declare an array to store cumulative changes

        // Read each interval and update the cumulative changes in the array
        for (int i = 0; i < n; i++) {
            int l = scanner.nextInt(); // Read the left endpoint
            int r = scanner.nextInt(); // Read the right endpoint
            mem[l]++; // Increment the value at the left endpoint
            mem[r]--; // Decrement the value at the right endpoint
        }

        // Initialize ans with the value at mem[0]
        int ans = mem[0];

        // Compute the prefix sum and find the maximum value in the array
        for (int i = 1; i < t + 1; i++) {
            mem[i] += mem[i - 1]; // Compute the prefix sum
            if (ans < mem[i]) { // Update ans if a larger value is found
                ans = mem[i];
            }
        }

        // Print the maximum value found
        System.out.println(ans);
    }
}

