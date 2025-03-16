import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of elements (n) and the threshold value (m)
        int n = sc.nextInt(); 
        int m = sc.nextInt(); 
        
        // Initialize two queues: one for the values and one for their original indices
        Queue<Integer> q1 = new LinkedList<>(); 
        Queue<Integer> q2 = new LinkedList<>(); 
        
        // Populate the queues with input values and their corresponding indices
        for (int i = 1; i <= n; i++) { 
            q1.add(sc.nextInt()); // Add the value to the first queue
            q2.add(i); // Add the index to the second queue
        } 
        
        // Variable to store the final answer (the index of the last processed element)
        int ans = 0; 
        
        // Process the elements in the queue until it is empty
        while (!q1.isEmpty()) { 
            // Check if the front element of q1 is less than or equal to m
            if (q1.peek() <= m) { 
                // If yes, remove it from q1 and update the answer with the corresponding index from q2
                q1.poll(); 
                ans = q2.poll(); 
            } 
            // If the front element is greater than m
            else if (q1.peek() > m) { 
                // Remove the element, reduce it by m, and add it back to q1
                int x = q1.poll(); 
                int val = x - m; 
                q1.add(val); 
                
                // Remove the index from q2 and add it back to maintain the order
                int val2 = q2.poll(); 
                q2.add(val2); 
            } 
        } 
        
        // Output the final answer
        System.out.println(ans); 
    } 
}
