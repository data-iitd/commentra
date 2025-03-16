import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements (N) and the number of comparisons (M)
        int N = sc.nextInt(); 
        long M = sc.nextLong(); 
        
        // Initialize an array to hold the heights and a boolean array to track valid heights
        long[] H = new long[N]; 
        boolean[] ans = new boolean[N]; 
        
        // Read the heights and initialize the ans array to true
        for (int i = 0; i < N; i++) { 
            H[i] = sc.nextLong(); // Read the height for each element
            ans[i] = true; // Assume all heights are valid initially
        } 
        
        // Process M comparisons between pairs of heights
        for (int i = 0; i < M; i++) { 
            int temp1 = sc.nextInt(); // Read the first index for comparison
            int temp2 = sc.nextInt(); // Read the second index for comparison
            
            // Compare the heights and update the ans array based on the comparison results
            if (H[temp1 - 1] < H[temp2 - 1]) { 
                ans[temp1 - 1] = false; // temp1 is shorter, mark it as invalid
            } else if (H[temp1 - 1] > H[temp2 - 1]) { 
                ans[temp2 - 1] = false; // temp2 is shorter, mark it as invalid
            } else { 
                // If heights are equal, mark both as invalid
                ans[temp1 - 1] = false; 
                ans[temp2 - 1] = false; 
            } 
        } 
        
        // Count the number of valid heights
        int ans2 = 0; 
        for (int i = 0; i < N; i++) { 
            if (ans[i]) { 
                ans2++; // Increment count for each valid height
            } 
        } 
        
        // Output the count of valid heights
        System.out.println(ans2); 
    } 
}
