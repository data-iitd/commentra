import java.io.*; 
import java.util.*; 

public class Main {
    // Constructor for the Main class
    Main() { 
        super(System.out, true); 
    } 
    
    // Scanner object to read input
    Scanner sc = new Scanner(System.in); 
    
    public static void main(String[] $) { 
        // Create an instance of Main and invoke the main logic
        Main o = new Main(); 
        o.main(); 
        o.flush(); 
    } 
    
    // Method to compare two character arrays with case insensitivity
    int compare(char[] aa, int i, char[] bb, int j, int m) { 
        while (m-- > 0) { 
            // Convert characters to uppercase for comparison
            char a = Character.toUpperCase(aa[i]); 
            char b = Character.toUpperCase(bb[j]); 
            // Return the difference if characters do not match
            if (a != b) return a - b; 
            i++; 
            j++; 
        } 
        // Return 0 if all characters match
        return 0; 
    } 
    
    void main() { 
        // Read the number of strings
        int n = sc.nextInt(); 
        char[][] ss = new char[n][]; 
        
        // Read each string and convert it to a character array
        for (int i = 0; i < n; i++) 
            ss[i] = sc.next().toCharArray(); 
        
        // Read the character array to be modified
        char[] cc = sc.next().toCharArray(); 
        int m = cc.length; 
        
        // Read the character to be replaced
        char c = sc.next().charAt(0); 
        char c_ = Character.toUpperCase(c); 
        
        // Determine the character to replace with
        char a = c == 'a' ? 'b' : 'a'; 
        char a_ = Character.toUpperCase(a); 
        
        // Array to track positions that can be marked as lucky
        boolean[] lucky = new boolean[m]; 
        
        // Loop through each position in the character array
        for (int j = 0; j < m; j++) 
            for (int i = 0; i < n; i++) { 
                int l = ss[i].length; 
                // Check if the substring matches and mark lucky positions
                if (m - j >= l && compare(cc, j, ss[i], 0, l) == 0) 
                    for (int h = 0; h < l; h++) 
                        lucky[j + h] = true; 
            } 
        
        // Replace characters in the original array based on lucky positions
        for (int j = 0; j < m; j++) 
            if (lucky[j]) { 
                // Replace with the determined character based on case
                if (Character.toLowerCase(cc[j]) == c) 
                    cc[j] = Character.isUpperCase(cc[j]) ? a_ : a; 
                else 
                    cc[j] = Character.isUpperCase(cc[j]) ? c_ : c; 
            } 
        
        // Print the modified character array
        println(cc); 
    }
}
