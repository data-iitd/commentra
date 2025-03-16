import java.util.*; 

public class Main { 

    // Depth-first search (DFS) method to determine if the target can be reached
    public static boolean dfs(int currpos, int[] arr, int target) { 
        // Base case: if the current position equals the target, return true
        if (currpos == target) 
            return true; 
        
        // Base case: if the current position exceeds the bounds of the array, return false
        if (currpos == arr.length + 1) 
            return false; 
        
        // Recursive case: attempt to teleport to the next position based on the current array value
        boolean teleport = dfs(currpos + arr[currpos - 1], arr, target); 
        
        // If teleporting leads to the target, return true
        if (teleport) 
            return true; 
        
        // If no valid path found, return false
        return false; 
    } 

    public static void main(String[] args) throws Exception { 
        // Create a Scanner object for input
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of positions (n) and the target position (goal)
        int n = sc.nextInt(); 
        int goal = sc.nextInt(); 
        
        // Initialize an array to hold the teleportation values
        int[] arr = new int[n - 1]; 
        
        // Populate the array with teleportation values from input
        for (int i = 0; i < n - 1; i++) 
            arr[i] = sc.nextInt(); 
        
        // Call the DFS function starting from position 1 to check if the goal can be reached
        boolean isFound = dfs(1, arr, goal); 
        
        // Output the result based on whether the goal was found
        if (isFound) 
            System.out.println("YES"); 
        else 
            System.out.println("NO"); 
        
        // Close the scanner to prevent resource leaks
        sc.close(); 
    } 
}
