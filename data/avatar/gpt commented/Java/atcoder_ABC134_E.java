import java.util.*; 

public class Main { 
    public static void main(String[] args) throws Exception { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of integers to process
        int n = sc.nextInt(); 
        
        // Initialize a TreeMap to store integers and their counts
        TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>(); 
        
        // Process each integer input
        while (n-- > 0) { 
            // Read the next integer
            int num = sc.nextInt(); 
            
            // Check if there is no lower key in the map
            if (map.lowerKey(num) == null) { 
                // If no lower key exists, increment the count for the current number
                int val = map.getOrDefault(num, 0); 
                map.put(num, ++val); 
            } else { 
                // If there is a lower key, get that key and its count
                int key = map.lowerKey(num); 
                int val = map.get(key); 
                
                // If the count of the lower key is 1, remove it from the map
                if (val == 1) { 
                    map.remove(key); 
                } else { 
                    // Otherwise, decrement the count of the lower key
                    map.put(key, --val); 
                }
                
                // Increment the count for the current number
                val = map.getOrDefault(num, 0); 
                map.put(num, ++val); 
            } 
        } 
        
        // Initialize a variable to hold the final answer
        int ans = 0; 
        
        // Sum up all the counts in the map
        for (Integer key : map.keySet()) { 
            int val = map.get(key); 
            ans += val; 
        } 
        
        // Print the final answer
        System.out.println(ans); 
    } 
}
