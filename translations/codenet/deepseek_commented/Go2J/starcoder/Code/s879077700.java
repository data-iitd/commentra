import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare a string variable to store the input
        String a;
        
        // Read a string input from the user and store it in `a`
        Scanner sc = new Scanner(System.in);
        a = sc.next();
        
        // Initialize the variable `ans` with the value "Good"
        String ans = "Good";
        
        // Loop through the first three characters of the string `a`
        for (int i = 0; i < 3; i++) {
            // Check if the current character is the same as the next character
            if (a.charAt(i) == a.charAt(i+1)) {
                // If the condition is true, change the value of `ans` to "Bad"
                ans = "Bad";
            }
        }
        
        // Print the value of `ans`
        System.out.println(ans);
    }
}

