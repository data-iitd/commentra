import java.util.HashMap; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of strings to be processed
        int N = sc.nextInt(); 
        
        // Initialize a HashMap to store the strings with their corresponding indices
        HashMap<Integer, String> map = new HashMap<>(); 
        
        // Read N strings from the input and store them in the map
        for (int i = 0; i < N; i++) { 
            map.put(i, sc.next()); 
        } 
        
        // Initialize a boolean variable to track if the conditions are met
        boolean ans = true; 
        
        // Initialize a HashMap to keep track of previously seen strings
        HashMap<Integer, String> past = new HashMap<>(); 
        
        // Variable to hold the last character of the previous string
        String next = ""; 
        
        // Iterate through the strings to check the conditions
        for (int i = 0; i < N; i++) { 
            // Check if the current string has already been seen
            if (past.containsValue(map.get(i))) { 
                ans = false; // Set answer to false if a duplicate is found
                break; 
            } 
            
            // Store the current string in the past map
            past.put(i, map.get(i)); 
            
            // Check if this is not the first string
            if (i != 0) { 
                // Check if the first character of the current string matches the last character of the previous string
                if (!next.equals(map.get(i).substring(0, 1))) { 
                    ans = false; // Set answer to false if the characters do not match
                    break; 
                } 
            } 
            
            // Update 'next' to the last character of the current string
            next = map.get(i).substring(map.get(i).length() - 1, map.get(i).length()); 
        } 
        
        // Output the result based on the value of ans
        if (ans) { 
            System.out.println("Yes"); // Print "Yes" if all conditions are satisfied
        } else { 
            System.out.println("No"); // Print "No" if any condition fails
        } 
    } 
}
