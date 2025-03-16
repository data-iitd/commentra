import java.util.ArrayList; 
import java.util.HashMap; 
import java.util.List; 
import java.util.Map; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in); 
        
        // Read the number of elements
        int N = scan.nextInt(); 
        
        // Initialize an array to store the elements, adjusting for zero-based indexing
        int[] P = new int[N]; 
        for (int i = 0; i < N; ++i) 
            P[i] = scan.nextInt() - 1; // Store input values after decrementing by 1
        
        // Create a map to store the index of each element for quick lookup
        Map<Integer, Integer> map = new HashMap<>(); 
        for (int i = 0; i < N; ++i) 
            map.put(P[i], i); // Map each value to its index
        
        // List to store indices where the order is not increasing
        List<Integer> nglist = new ArrayList<>(); 
        for (int i = 0; i < N - 1; ++i) 
            // Check if the current index is greater than the next index in the map
            if (map.get(i) > map.get(i + 1)) 
                nglist.add(i); // Add the index to the nglist if the order is violated
        
        // If there are no indices in nglist, print 0 and exit
        if (nglist.isEmpty()) { 
            System.out.println(0); 
            return; 
        } 
        
        // Calculate the minimum number of moves required to fix the order
        int ans = Math.min(N - nglist.get(0) - 1, nglist.get(nglist.size() - 1) + 1); 
        for (int i = 0; i < nglist.size() - 1; ++i) 
            // Update ans with the minimum moves needed between consecutive indices in nglist
            ans = Math.min(nglist.get(i) + 1 + N - nglist.get(i + 1) - 1, ans); 
        
        // Print the result which is the minimum number of moves
        System.out.println(ans); 
    } 
}
