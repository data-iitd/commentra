import java.util.*; 

public class Main {
    // Define a constant for infinity, used for comparison
    int INF = Integer.MAX_VALUE; 

    public static void main(String[] args) {
        // Create an instance of Main and call the solve method to execute the program
        new Main().solve();
    } 

    void solve() {
        // Initialize a Scanner to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements N and the multiplier X
        int N = sc.nextInt(); 
        long X = sc.nextLong(); 
        
        // Initialize an array to store the elements and a prefix sum array
        long[] x = new long[N]; 
        long[] xsum = new long[N + 1]; 
        
        // Read the elements into the array and compute the prefix sums
        for (int i = 0; i < N; i++) { 
            x[i] = sc.nextInt(); 
            xsum[i + 1] = xsum[i] + x[i]; 
        } 
        
        // Initialize the answer with the cost of processing all elements with the base cost
        long ans = X * N + 5 * xsum[N]; 
        
        // Iterate through possible splits of the array
        for (int i = 1; i < N; i++) { 
            // Calculate the cost for the current split
            long cost = X * i + 5 * (xsum[N] - xsum[N - i]); 
            
            // Incrementally add costs based on the current split
            for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) { 
                // If the current cost exceeds the best answer found, break out of the loop
                if (cost > ans) { 
                    break; 
                } 
                // Update the cost based on the prefix sums
                cost += j * (xsum[k] - xsum[Math.max(k - i, 0)]); 
            } 
            // Update the answer with the minimum cost found
            ans = Math.min(ans, cost); 
        } 
        
        // Output the final answer, which includes the base cost
        System.out.println(ans + N * X); 
    } 
}
