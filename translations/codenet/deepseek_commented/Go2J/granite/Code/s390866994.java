
import java.util.Arrays;
import java.util.Scanner;

public class s390866994{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read input values
        int N = sc.nextInt(); // Number of passengers
        int C = sc.nextInt(); // Bus capacity
        int K = sc.nextInt(); // Time window

        // Array to store arrival times
        int[] t = new int[N];
        for (int i = 0; i < N; i++) {
            t[i] = sc.nextInt();
        }

        // Sort the arrival times
        Arrays.sort(t);

        // Initialize variables for the number of buses and passengers in the current bus
        int ans = 1;
        int cnt = 1;
        int end = t[0] + K; // Time when the bus will be full or the time window expires

        // Iterate through the sorted arrival times
        for (int i = 1; i < N; i++) {
            if (cnt < C && t[i] <= end) {
                // The current passenger can fit in the bus
                cnt++;
            } else {
                // The current bus is full or the time window has expired
                // Increment the bus count, reset the count, and update the end time
                cnt = 1;
                end = t[i] + K;
                ans++;
            }
        }

        // Output the number of buses required
        System.out.println(ans);
    }
}

