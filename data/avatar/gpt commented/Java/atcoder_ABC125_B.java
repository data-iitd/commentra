import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of items (n) from the input
        Integer n = Integer.valueOf(sc.nextLine()); 
        
        // Read the values (vStr) from the input and convert to a list
        String vStr = sc.nextLine(); 
        Map<Integer, Integer> vList = str2List(vStr); 
        
        // Read the costs (cStr) from the input and convert to a list
        String cStr = sc.nextLine(); 
        Map<Integer, Integer> cList = str2List(cStr); 
        
        // Initialize a variable to keep track of the maximum profit
        Integer max = 0; 
        
        // Calculate the profit for each item and sum up the positive profits
        for (Integer i = 0; i < n; i++) { 
            Integer profit = vList.get(i) - cList.get(i); 
            // Only add to max if the profit is positive
            if (profit > 0) { 
                max += profit; 
            } 
        } 
        
        // Output the total maximum profit
        System.out.println(max); 
    } 
    
    // Helper method to convert a space-separated string of integers into a Map
    static Map<Integer, Integer> str2List(String str) { 
        // Split the input string into an array of strings
        String[] vArrStr = str.split(" "); 
        
        // Create a Map to hold the integer values with their corresponding indices
        Map<Integer, Integer> ret = new HashMap<>(); 
        Integer key = 0; 
        
        // Populate the Map with values from the array
        for (String val : vArrStr) { 
            ret.put(key, Integer.valueOf(val)); 
            key++; 
        } 
        
        // Return the populated Map
        return ret; 
    } 
}
