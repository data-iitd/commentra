import java.util.ArrayList; 
import java.util.Scanner; 

public class Main { 
    // Declare arrays to hold input values and variables for dimensions and result
    static int[] a = null; 
    static int[] b = null; 
    static int[] c = null; 
    static int[] d = null; 
    static int n = 0; 
    static int m = 0; 
    static int q = 0; 
    static long ans = -100L; // Initialize answer to a very low value

    public static void main(String[] args) { 
        // Create a Scanner object for input
        Scanner sc = new Scanner(System.in); 
        
        // Read the values of n, m, and q from input
        n = sc.nextInt(); 
        m = sc.nextInt(); 
        q = sc.nextInt(); 
        
        // Initialize arrays based on the number of queries (q)
        a = new int[q]; 
        b = new int[q]; 
        c = new int[q]; 
        d = new int[q]; 
        
        // Read the query parameters into the arrays
        for (int i = 0; i < q; ++i) { 
            a[i] = sc.nextInt() - 1; // Store a[i] (0-indexed)
            b[i] = sc.nextInt() - 1; // Store b[i] (0-indexed)
            c[i] = sc.nextInt();      // Store c[i]
            d[i] = sc.nextInt();      // Store d[i]
        } 
        
        // Start the depth-first search (DFS) to find the maximum score
        dfs(new ArrayList<Integer>()); 
        
        // Output the maximum score found
        System.out.println(ans); 
    } 

    public static void dfs(ArrayList<Integer> list) { 
        // Check if the current list has reached the required size (n)
        if (list.size() == n) { 
            long score = 0L; // Initialize score for the current configuration
            
            // Calculate the score based on the queries
            for (int i = 0; i < q; ++i) { 
                // If the condition is met, add the corresponding value to the score
                score += (list.get(b[i]) - list.get(a[i]) == c[i]) ? d[i] : 0L; 
            } 
            
            // Update the maximum score if the current score is higher
            ans = Math.max(ans, score); 
            return; 
        } 
        
        // If the list is not empty, continue adding numbers from the last added number to m
        if (!list.isEmpty()) { 
            for (int num = list.get(list.size() - 1); num <= m; ++num) { 
                list.add(num); // Add the current number to the list
                dfs(list);     // Recur with the updated list
                list.remove(list.size() - 1); // Backtrack by removing the last number
            } 
        } else { 
            // If the list is empty, start adding numbers from 1 to m
            for (int num = 1; num <= m; ++num) { 
                list.add(num); // Add the current number to the list
                dfs(list);     // Recur with the updated list
                list.remove(list.size() - 1); // Backtrack by removing the last number
            } 
        } 
    } 
}
