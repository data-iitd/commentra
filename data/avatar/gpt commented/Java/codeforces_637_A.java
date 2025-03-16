import java.io.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object for input and PrintWriter for output
        Scanner in = new Scanner(System.in); 
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read the number of elements
        int n = in.nextInt(); 
        
        // Initialize an array to store the elements
        int ara[] = new int[n]; 
        
        // Create a map to count the frequency of each element
        Map<Integer, Integer> map = new HashMap<>(); 
        
        // Read elements and populate the frequency map
        for (int i = 0; i < n; i++) { 
            int v = in.nextInt(); 
            ara[i] = v; 
            // If the element is not in the map, add it with a count of 1
            if (!map.containsKey(v)) { 
                map.put(v, 1); 
            } else { 
                // If it is already in the map, increment its count
                map.put(v, map.get(v) + 1); 
            } 
        } 
        
        // Find the maximum frequency among the elements
        int max = 0; 
        for (Integer i : map.values()) { 
            max = Math.max(max, i); 
        } 
        
        // Create another map to track the order of elements while checking frequency
        Map<Integer, Integer> mm = new HashMap<>(); 
        
        // Iterate through the original array to find the first element with maximum frequency
        for (int i = 0; i < n; i++) { 
            if (!mm.containsKey(ara[i])) { 
                mm.put(ara[i], 1); 
                // Check if the current element's frequency matches the maximum frequency
                if (mm.get(ara[i]) == max) { 
                    pw.println(ara[i]); 
                    break; 
                } 
            } else { 
                // Increment the count for the existing element
                mm.put(ara[i], mm.get(ara[i]) + 1); 
                // Check if the current element's frequency matches the maximum frequency
                if (mm.get(ara[i]) == max) { 
                    pw.println(ara[i]); 
                    break; 
                } 
            } 
        } 
        
        // Close the PrintWriter
        pw.close(); 
    } 
    
    // Debugging method to print objects
    static void debug(Object... obj) { 
        System.err.println(Arrays.deepToString(obj)); 
    } 
}
