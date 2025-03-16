import java.io.*; 
import java.lang.*; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner s = new Scanner(System.in); 
        
        // Read two strings from the input
        String s1 = s.next(); 
        String s2 = s.next(); 
        
        // Validate the input strings; if invalid, print -1 and exit
        if (isValid(s1, s2) == false) { 
            System.out.println(-1); 
        } else { 
            // Create HashMaps to count the frequency of characters in both strings
            HashMap<Character, Integer> m1 = new HashMap<>(); 
            HashMap<Character, Integer> m2 = new HashMap<>(); 
            
            // Count the frequency of each character in the first string
            for (char c : s1.toCharArray()) { 
                if (m1.containsKey(c)) { 
                    m1.put(c, m1.get(c) + 1); 
                } else { 
                    m1.put(c, 1); 
                } 
            } 
            
            // Count the frequency of each character in the second string
            for (char c : s2.toCharArray()) { 
                if (m2.containsKey(c)) { 
                    m2.put(c, m2.get(c) + 1); 
                } else { 
                    m2.put(c, 1); 
                } 
            } 
            
            // Initialize a variable to hold the result
            int ans = 0; 
            // Create a HashSet to track unique characters from the second string
            HashSet<Character> hs = new HashSet<>(); 
            
            // Calculate the minimum frequency of each character present in both strings
            for (char c : s2.toCharArray()) { 
                if (!hs.contains(c)) { 
                    hs.add(c); 
                    int x1 = m1.get(c); // Frequency in the first string
                    int x2 = m2.get(c); // Frequency in the second string
                    x1 = Math.min(x1, x2); // Take the minimum frequency
                    ans += x1; // Add to the result
                } 
            } 
            // Print the final result
            System.out.println(ans); 
        } 
    } 
    
    // Method to check if the characters in s2 are all present in s1
    public static boolean isValid(String s1, String s2) { 
        int n1 = s1.length(); 
        int n2 = s2.length(); 
        // Create a HashMap to store characters from the first string
        HashMap<Character, Boolean> map = new HashMap<>(); 
        
        // Add all characters from the first string to the map
        for (char c : s1.toCharArray()) { 
            map.put(c, true); 
        } 
        
        // Check if all characters in the second string are present in the first string
        for (char c : s2.toCharArray()) { 
            if (!map.containsKey(c)) return false; 
        } 
        return true; // All characters are valid
    } 
}
