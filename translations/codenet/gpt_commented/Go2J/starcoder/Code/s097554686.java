import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of intervals and the maximum time from input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();

        // Create an array to store the count of overlapping intervals at each time point
        int[] mem = new int[t + 1];

        // Process each interval
        for (int i = 0; i < n; i++) {
            // Read the left and right bounds of the interval
            int l = sc.nextInt();
            int r = sc.nextInt();
            // Increment the count at the start of the interval
            mem[l] += 1;
            // Decrement the count just after the end of the interval
            mem[r] -= 1;
        }

        // Initialize the answer with the count at time 0
        int ans = mem[0];

        // Calculate the number of overlapping intervals at each time point
        for (int i = 1; i < t + 1; i++) {
            // Update the current count based on the previous count
            mem[i] += mem[i - 1];
            // Update the answer if the current count is greater than the previous maximum
            if (ans < mem[i]) {
                ans = mem[i];
            }
        }

        // Print the maximum number of overlapping intervals
        System.out.println(ans);
    }
}

