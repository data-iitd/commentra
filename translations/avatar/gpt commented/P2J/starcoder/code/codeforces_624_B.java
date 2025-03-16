import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements
        int n = sc.nextInt();
        
        // Read the list of integers and convert them to a list of integers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Initialize the previous value to infinity
        int pre = Integer.MAX_VALUE;
        
        // Initialize the answer variable to accumulate the result
        int ans = 0;
        
        // Sort the list in descending order
        Arrays.sort(a);
        
        // Iterate through the sorted list
        for (int j = 0; j < n; j++) {
            // Calculate the current contribution to the answer
            // It takes the minimum of (pre - 1) and the current element a[j], ensuring it's non-negative
            ans += Math.max(0, Math.min(pre - 1, a[j]));
            
            // Update the previous value for the next iteration
            pre = Math.max(0, Math.min(pre - 1, a[j]));
        }
        
        // Print the final accumulated answer
        System.out.println(ans);
    }
}

