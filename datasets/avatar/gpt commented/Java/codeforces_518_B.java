import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in); 
        
        // Read the first string and initialize a StringBuilder with it
        StringBuilder s = new StringBuilder(scan.next()); 
        
        // Read the second string
        String t = scan.next(); 
        
        // Initialize counters for unique characters replaced (ura) and reversed characters (opa)
        int ura = 0; 
        int opa = 0; 
        
        // Create a map to count occurrences of each character in string t
        Map<Character, Integer> tmap = new HashMap<>(); 
        
        // Populate the character frequency map for string t
        for (int i = 0; i < t.length(); i++) { 
            Character ch = t.charAt(i); 
            // If the character is not already in the map, add it with a count of 1
            if (!tmap.containsKey(ch)) 
                tmap.put(ch, 1); 
            else 
                // If it exists, increment its count
                tmap.put(ch, tmap.get(ch) + 1); 
        } 
        
        // Get the length of the StringBuilder for iteration
        int length = s.length(); 
        
        // First pass: Replace characters in s with 'Я' and update the frequency map
        for (int i = 0; i < length; i++) { 
            Character ch = s.charAt(i); 
            Integer num = tmap.get(ch); 
            // If the character is not in the map, skip it
            if (num == null) continue; 
            int inum = num; 
            // If the count is 1, remove it from the map; otherwise, decrement the count
            if (inum == 1) 
                tmap.remove(ch); 
            else 
                tmap.put(ch, inum - 1); 
            // Replace the character in the StringBuilder with 'Я'
            s.setCharAt(i, 'Я'); 
            // Increment the unique character replacement counter
            ura++; 
        } 
        
        // Second pass: Check for reversed characters and update the frequency map
        for (int i = 0; i < length; i++) { 
            Character ch = s.charAt(i); 
            // Get the reversed character (lowercase to uppercase or vice versa)
            Character rch = reverse(ch); 
            Integer num = tmap.get(rch); 
            // If the reversed character is not in the map, skip it
            if (num == null) continue; 
            int inum = num; 
            // If the count is 1, remove it from the map; otherwise, decrement the count
            if (inum == 1) 
                tmap.remove(rch); 
            else 
                tmap.put(rch, inum - 1); 
            // Increment the reversed character counter
            opa++; 
        } 
        
        // Output the counts of unique character replacements and reversed characters
        System.out.println(ura + " " + opa); 
    } 
    
    // Method to reverse the case of a character
    public static Character reverse(Character ch) { 
        // If the character is lowercase, convert it to uppercase
        if (Character.isLowerCase(ch)) { 
            return Character.toUpperCase(ch); 
        } else 
            // If it's uppercase, convert it to lowercase
            return Character.toLowerCase(ch); 
    } 
}
