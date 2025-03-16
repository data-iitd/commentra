import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements (n) and the maximum size of the queue (b)
        int n = sc.nextInt(); 
        int b = sc.nextInt(); 
        
        // Initialize an array to store the results
        long[] ans = new long[n]; 
        
        // Create a LinkedList to act as a queue for managing time values
        LinkedList<Long> q = new LinkedList<>(); 
        
        // Process each element based on the input
        for (int i = 0; i < n; i++) { 
            // Read the time (t) and duration (d) for the current element
            int t = sc.nextInt(); 
            int d = sc.nextInt(); 
            
            // Remove elements from the front of the queue that are no longer valid (i.e., their time is less than or equal to t)
            while (!q.isEmpty() && q.getFirst() <= t) { 
                q.pollFirst(); 
            } 
            
            // Check if the size of the queue is within the allowed limit
            if (q.size() <= b) { 
                // If the queue is empty, set the answer to the current time (t) plus duration (d)
                // Otherwise, set it to the last element in the queue plus duration (d)
                ans[i] = (q.isEmpty() ? t : q.getLast()) + d; 
                
                // Add the computed answer to the queue
                q.add(ans[i]); 
            } else { 
                // If the queue size exceeds the limit, set the answer to -1
                ans[i] = -1; 
            } 
        } 
        
        // Print the results stored in the ans array
        for (int i = 0; i < n; ++i) { 
            System.out.print(ans[i] + " "); 
        } 
    } 
}
