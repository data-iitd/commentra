import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare a string 'c' to store the input string and 'ans' to store the result
        String c, ans = "";
        
        // Read a string input from the user
        Scanner sc = new Scanner(System.in);
        c = sc.next();
        
        // Iterate through each character of the input string until the null terminator is encountered
        for (int i = 0; i < c.length(); i++) {
            // If the current character is not 'B', append it to the 'ans' string
            if (c.charAt(i)!= 'B') {
                ans += c.charAt(i);
            } 
            // If the current character is 'B', remove the last character from 'ans' (if it exists)
            else {
                ans = ans.substring(0, ans.length() - 1);
            }
        }
        
        // Print the resulting string after processing the input
        System.out.println(ans);
    }
}
