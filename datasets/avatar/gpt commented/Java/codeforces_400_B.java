import java.util.HashMap; 
import java.util.HashSet; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of strings (n) and the number of queries (m)
        int n = sc.nextInt(); 
        int m = sc.nextInt(); 
        
        // Initialize an array to store the strings
        String arrs[] = new String[n]; 
        
        // Read n strings from the input
        for (int i = 0; i < n; i++) { 
            arrs[i] = sc.next(); 
        } 
        
        // Initialize an array to store the lengths of segments between 'G' and 'S'
        int[] length = new int[n]; 
        int index = 0; 
        int returnDex = 0; 
        
        // Iterate through each string to find the indices of 'G' and 'S'
        for (String tmp : arrs) { 
            int dexG = tmp.indexOf("G"); // Find the index of 'G'
            int dexS = tmp.indexOf("S"); // Find the index of 'S'
            
            // If 'G' appears after 'S', set returnDex to -1
            if (dexG > dexS) { 
                returnDex = -1; 
            } 
            
            // Calculate the length between 'G' and 'S' and store it in the length array
            length[index++] = dexS - dexG; 
        } 
        
        // Use a HashSet to store unique lengths
        HashSet<Integer> set = new HashSet<Integer>(); 
        
        // Add each length to the HashSet to ensure uniqueness
        for (int len : length) { 
            set.add(len); 
        } 
        
        // Check if returnDex was set to -1 and print the appropriate result
        if (returnDex == -1) { 
            System.out.println(returnDex); // Print -1 if 'G' is after 'S' in any string
        } else { 
            System.out.println(set.size()); // Print the number of unique lengths
        } 
    } 
}
