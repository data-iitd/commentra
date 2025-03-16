import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the dimensions and rank
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        int rank = sc.nextInt();

        // Arrays to hold input values
        int[] xrr = new int[x];
        int[] yrr = new int[y];
        int[] zrr = new int[z];

        // Read the arrays from input
        for(int i = 0; i < x; i++) xrr[i] = sc.nextLong();
        for(int i = 0; i < y; i++) yrr[i] = sc.nextLong();
        for(int i = 0; i < z; i++) zrr[i] = sc.nextLong();

        // Initialize min and max sums
        long min_sum = Long.MAX_VALUE;
        long max_sum = Long.MIN_VALUE;

        // Calculate minimum and maximum values from zrr
        for(int i = 0; i < z; i++) min_sum = Math.min(min_sum, zrr[i]);
        for(int i = 0; i < z; i++) max_sum = Math.max(max_sum, zrr[i]);

        // Create an array to hold the sums of pairs from xrr and yrr
        long[] pair = new long[x * y];

        // Calculate all possible sums of pairs from xrr and yrr
        int idx = 0;
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                pair[idx++] = xrr[i] + yrr[j];
            }
        }

        // Sort the pair array in ascending order
        Arrays.sort(pair);

        // Update min and max sums with the smallest and largest pair sums
        min_sum += pair[0];
        max_sum += pair[idx - 1];

        // Arrays for caching and counting
        int[] cache = new int[z];
        int[] cnt_map = new int[z];
        long[] ans = new long[rank];

        // Calculate the size of the combined array
        int size = x * y * z;
        long prev = min_sum;
        int r;

        // Iterate to find the rank-th largest sum
        for(r = rank; r >= 1; r--) {
            long low = prev - 1;
            long high = max_sum + 1;

            // Binary search to find the appropriate sum
            while(low + 1 < high) {
                long mid = (low + high) / 2;
                int cnt = 0;

                // Count how many sums are less than or equal to mid
                for(int i = 0; i < z; i++) {
                    long pivot = zrr[i];
                    int tmp = lower_bound(pair, cache[i] - 1, idx, mid - pivot);
                    cnt_map[i] = tmp;
                    cnt += tmp;
                }

                // Adjust the search range based on the count
                if(cnt <= size - r) {
                    System.arraycopy(cnt_map, 0, cache, 0, z);
                    low = mid;
                } else {
                    high = mid;
                }
            }

            // Store the found sum in the answer array
            ans[r - 1] = low;
            if(low == max_sum) break; // Stop if we reach the maximum sum
            prev = low; // Update previous sum for the next iteration
        }

        // Print the results for each rank
        for(int i = 0; i < rank; i++) {
            System.out.println((ans[i] == 0)? max_sum : ans[i]);
        }
    }

    // Function to find the lower bound index of a key in a sorted array
    public static int lower_bound(long[] arr, int low, int high, long key) {
        while(low + 1 < high) {
            int mid = (low + high) / 2;
            if(arr[mid] < key) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low + 1; // Return the index of the first element greater than key
    }
}

