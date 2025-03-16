import java.util.Scanner;

public class Main {
    // Define a constant for the maximum size of the memory array
    static final int SIZE = 100001;

    public static void main(String[] args) {
        // Declare variables for the number of intervals (n), the maximum time (t),
        // and the left (l) and right (r) bounds of each interval
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int t = scanner.nextInt();
        int l, r;
        
        // Create an array to store the count of overlapping intervals at each time point
        int[] mem = new int[SIZE];

        // Process each interval
        for (int i = 0; i < n; i++) {
            // Read the left and right bounds of the interval
            l = scanner.nextInt();
            r = scanner.nextInt();
            // Increment the count at the start of the interval
            mem[l] += 1;
            // Decrement the count just after the end of the interval
            mem[r] -= 1;
        }

        // Initialize the answer with the count at time 0
        int ans = mem[0];

        // Calculate the number of overlapping intervals at each time point
        for (int i = 1; i <= t; i++) {
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
// <END-OF-CODE>
