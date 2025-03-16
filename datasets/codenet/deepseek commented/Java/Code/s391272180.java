import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Create StringBuilder objects to store the input strings
        StringBuilder s, t;
        s = new StringBuilder(sc.next());
        t = new StringBuilder(sc.next());
        
        // Initialize a boolean flag to false to track if strings are rotations of each other
        boolean flag = false;
        
        // Loop through the length of string s to check for rotation
        for (int i = 0; i < s.length(); i++) {
            // Rotate the string s in each iteration
            s = new StringBuilder(Rotate(s));
            
            // Check if the rotated string s is equal to string t
            if (t.toString().equals(s.toString())) {
                flag = true;
                break; // Exit the loop if a match is found
            }
        }
        
        // Print "Yes" if the strings are rotations of each other, otherwise print "No"
        if (flag)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
    
    // Method to rotate the given StringBuilder object by moving the first character to the end
    public static StringBuilder Rotate(StringBuilder str) {
        int len = str.length();
        char t = str.charAt(0);
        
        // Shift characters to the left
        for (int i = 0; i < len - 1; i++) {
            str.setCharAt(i, str.charAt(i + 1));
        }
        
        // Set the last character to the first character
        str.setCharAt(len - 1, t);
        
        return str;
    }
}
