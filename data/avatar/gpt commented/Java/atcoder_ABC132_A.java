import java.util.HashMap; 
import java.util.Map.Entry; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in); 
        
        // Read the input string from the user
        String s = in.next(); 
        
        // Convert the input string to a character array
        char[] targ = s.toCharArray(); 
        
        // Initialize a HashMap to store the frequency of each character
        HashMap<Character, Integer> map = new HashMap<>(); 
        
        // Loop through each character in the array
        for (int i = 0; i < targ.length; i++) { 
            // If the character is not already in the map, add it with a count of 1
            if (!map.containsKey(targ[i])) { 
                map.put(targ[i], 1); 
            } else { 
                // If the character is already in the map, increment its count
                map.put(targ[i], map.get(targ[i]) + 1); 
            } 
        } 
        
        // Initialize a boolean variable to check if the conditions are met
        boolean ok = true; 
        
        // Check if each character appears exactly twice
        for (Entry<Character, Integer> c : map.entrySet()) { 
            if (c.getValue() != 2) { 
                ok = false; // Set ok to false if any character does not appear twice
                break; 
            } 
        } 
        
        // Check if there are exactly two unique characters that appear twice
        if (ok && map.size() == 2) { 
            System.out.println("Yes"); // Output "Yes" if conditions are satisfied
        } else { 
            System.out.println("No"); // Output "No" if conditions are not satisfied
        } 
        
        // Close the scanner to prevent resource leaks
        in.close(); 
    } 
}
