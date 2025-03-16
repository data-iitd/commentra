import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Initialize StringBuilder objects for the two input strings
        StringBuilder s, t;
        s = new StringBuilder(sc.next()); // Read the first string
        t = new StringBuilder(sc.next()); // Read the second string
        
        // Flag to indicate if a rotation match is found
        boolean flag = false;
        
        // Loop through the length of the first string
        for (int i = 0; i < s.length(); i++) {
            // Rotate the string 's' to the left by one character
            s = new StringBuilder(Rotate(s));
            
            // Check if the rotated string matches the second string 't'
            if (t.toString().equals(s.toString())) {
                flag = true; // Set flag to true if a match is found
                break; // Exit the loop as we found a match
            }
        }
        
        // Output the result based on the flag
        if (flag == true)
            System.out.println("Yes"); // Print "Yes" if a rotation match was found
        else
            System.out.println("No"); // Print "No" if no match was found
    }
    
    // Method to rotate the string to the left by one character
    public static StringBuilder Rotate(StringBuilder str) {
        int len = str.length(); // Get the length of the string
        char t = str.charAt(0); // Store the first character to rotate
        
        // Shift all characters to the left by one position
        for (int i = 0; i < len - 1; i++) {
            str.setCharAt(i, str.charAt(i + 1));            
        }
        
        // Set the last character to the previously stored first character
        str.setCharAt(len - 1, t);
        
        // Return the rotated string
        return str;
    }
}
