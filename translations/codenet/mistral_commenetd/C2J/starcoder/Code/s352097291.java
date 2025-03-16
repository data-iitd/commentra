
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        String c = ""; // An array to store the input string
        String ans = ""; // An array to store the output string

        // Initialize variables
        Scanner sc = new Scanner(System.in);
        c = sc.next(); // Read a string from the standard input and store it in the 'c' array

        // Process the string
        for(int i=0;i<c.length();i++){ // Iterate through each character in the string 'c'
            if(!c.substring(i,i+1).equals("B")){ // If the current character is not 'B'
                ans += c.substring(i,i+1); // Append the character to the output string 'ans'
            }
        }

        // Print the output
        System.out.println(ans); // Print the final output string
    }
}

