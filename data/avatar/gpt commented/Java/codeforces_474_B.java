import java.util.*; 
import java.io.*; 

public class Main { 
    public static void main(String args[]) throws IOException { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements in the array
        int n = sc.nextInt(); 
        
        // Initialize the array to store cumulative sums
        int arr[] = new int[n]; 
        
        // Read the first element and assign it to the first index of the array
        arr[0] = sc.nextInt(); 
        
        // Populate the array with cumulative sums
        for (int i = 1; i < n; i++) { 
            // Read the next integer and add it to the previous cumulative sum
            int x = sc.nextInt(); 
            arr[i] = x + arr[i - 1]; 
        } 
        
        // Read the number of queries
        int m = sc.nextInt(); 
        
        // Initialize the array to store the queries
        int q[] = new int[m]; 
        
        // Read each query into the array
        for (int i = 0; i < m; i++) 
            q[i] = sc.nextInt(); 
        
        // Process each query and print the result
        for (int k = 0; k < m; k++) 
            System.out.println(fun(arr, q[k], n, m) + 1); 
    } 
    
    // Function to perform binary search on the cumulative sum array
    static int fun(int arr[], int q, int n, int m) { 
        int res = 0; // Variable to store the result index
        int i = 0, j = n; // Initialize pointers for binary search
        
        // Perform binary search to find the appropriate index
        while (i <= j) { 
            int md = i + (j - i) / 2; // Calculate the mid index
            
            // If the middle element is equal to the query, return the index
            if (arr[md] == q) 
                return md; 
            // If the middle element is greater than the query, adjust the search range
            else if (arr[md] > q) { 
                res = md; // Update result to the current mid index
                j = md - 1; // Move the end pointer left
            } else 
                i = md + 1; // Move the start pointer right
        } 
        
        // Return the last found index where the cumulative sum is less than the query
        return res; 
    } 
}
