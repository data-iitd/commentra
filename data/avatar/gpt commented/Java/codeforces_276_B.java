import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.io.PrintWriter; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) throws NumberFormatException, IOException { 
        // Initialize input stream to read from standard input
        InputStreamReader inputStreamReader = new InputStreamReader(System.in); 
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader); 
        PrintWriter writer = new PrintWriter(System.out); 
        
        // Read a line of input from the user
        String str = bufferedReader.readLine(); 
        
        // Create a map to count occurrences of each character
        Map<Character, Integer> map = new HashMap<>(); 
        int oddCount = 0; // Initialize counter for characters with odd occurrences
        
        // Iterate through each character in the input string
        for (int i = 0; i < str.length(); i++) { 
            char ch = str.charAt(i); 
            // Update the count of the character in the map
            if (map.containsKey(ch)) { 
                map.put(ch, map.get(ch) + 1); 
            } else { 
                map.put(ch, 1); 
            } 
        } 
        
        // Count how many characters have an odd number of occurrences
        for (Map.Entry<Character, Integer> entry : map.entrySet()) { 
            if (entry.getValue() % 2 != 0) { 
                oddCount++; 
            } 
        } 
        
        // Determine the output based on the count of odd occurrences
        if (oddCount <= 1 || oddCount % 2 != 0) { 
            writer.println("First"); // Output "First" if conditions are met
        } else { 
            writer.println("Second"); // Output "Second" otherwise
        } 
        
        // Flush the output to ensure all data is written
        writer.flush(); 
    } 
}
