import java.util.ArrayList; 
import java.util.Scanner; 
import java.lang.Math; 

public class Main { 
    // Define a constant for infinity
    static final int INF = (int) 1e9 + 5; 
    
    public static void main(String[] args) { 
        // Create a Scanner object for input
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of pairs
        int n; 
        n = sc.nextInt(); 
        
        // Initialize two ArrayLists to store the pairs
        ArrayList<Integer> a = new ArrayList<>(); 
        ArrayList<Integer> b = new ArrayList<>(); 
        
        // Initialize left to infinity and right to zero
        int left = INF, right = 0; 
        
        // Read the pairs and determine the minimum and maximum values
        for (int i = 0; i < n; i++) { 
            a.add(sc.nextInt()); // Read the first element of the pair
            b.add(sc.nextInt()); // Read the second element of the pair
            
            // Update left to the minimum value found in a
            left = Math.min(left, a.get(i)); 
            // Update right to the maximum value found in b
            right = Math.max(right, b.get(i)); 
        } 
        
        // Check for a pair that matches the left and right bounds
        for (int i = 0; i < n; i++) { 
            // If the current pair matches the min and max values
            if (left == a.get(i) && right == b.get(i)) { 
                // Print the index (1-based) and exit
                System.out.println(++i); 
                return; 
            } 
        } 
        
        // If no matching pair is found, print -1
        System.out.println(-1); 
    } 
}
