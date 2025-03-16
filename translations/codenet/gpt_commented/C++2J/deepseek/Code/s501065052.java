public class Main {
    public static void main(String[] args) {
        // Read the number of elements
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();

        // Create an array to store the positions of elements
        int[] mem = new int[N + 1];

        // Populate the 'mem' array with the positions of each element
        for (int i = 1; i <= N; ++i) {
            int P = scanner.nextInt(); // Read the element
            mem[P] = i; // Store the position of the element in 'mem'
        }

        // Initialize counters for the longest increasing subsequence
        int maxcnt = 1; // Maximum count of increasing sequence found
        int cnt = 1; // Current count of increasing sequence

        // Iterate through the 'mem' array to find the longest increasing subsequence
        for (int i = 1; i < N; ++i) {
            // Check if the current position is less than the next position
            if (mem[i] < mem[i + 1]) {
                cnt++; // Increment the current count if increasing
            } else {
                // Update the maximum count if the current count is greater
                maxcnt = Math.max(maxcnt, cnt);
                cnt = 1; // Reset current count
            }
            // Check at the last element to update max count
            if (i == N - 1) {
                maxcnt = Math.max(maxcnt, cnt);
            }
        }

        // Output the minimum number of elements to remove to get the longest increasing subsequence
        System.out.println(N - maxcnt);
    }
}
