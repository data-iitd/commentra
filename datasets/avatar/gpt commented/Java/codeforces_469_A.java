import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of players (n) and the number of levels (levels)
        int n = sc.nextInt(); 
        int levels = sc.nextInt(); 
        
        // Initialize variables to keep track of sums and counts
        int sum = 0; 
        int sum2 = 0; 
        int sum3 = 0; 
        
        // Create an array to store the levels completed by the first player
        int[] arr = new int[levels]; 
        int count = 0; 
        
        // Read the levels completed by the first player
        for (int i = 0; i < levels; i++) { 
            arr[i] = sc.nextInt(); 
        } 
        
        // Read the number of additional levels completed by the second player
        int level2 = sc.nextInt(); 
        
        // Calculate the total number of levels completed by both players
        int level3 = levels + level2; 
        
        // Create a new array to store levels completed by both players
        int[] arr2 = new int[level3]; 
        
        // Copy levels from the first player's array to the new array
        for (int i = 0; i < arr.length; i++) { 
            arr2[i] = arr[i]; 
        } 
        
        // Read the levels completed by the second player and add them to the new array
        for (int i = arr.length; i < level3; i++) { 
            arr2[i] = sc.nextInt(); 
        } 
        
        // Create an array to represent all levels (1 to n)
        int[] arr3 = new int[n]; 
        int j = 0; 
        
        // Fill arr3 with level numbers from 1 to n
        for (int i = 0; i < n; i++) { 
            arr3[i] = ++j; 
        } 
        
        // Check how many levels from arr3 are completed by either player
        for (int i = 0; i < n; i++) { 
            for (int x = 0; x < arr2.length; x++) { 
                // If a level is found in arr2, increment the count and break
                if (arr3[i] == arr2[x]) { 
                    count++; 
                    break; 
                } 
            } 
        } 
        
        // Determine if all levels have been completed by at least one player
        if (count == n) { 
            System.out.println("I become the guy."); 
        } else { 
            System.out.println("Oh, my keyboard!"); 
        } 
    } 
}
