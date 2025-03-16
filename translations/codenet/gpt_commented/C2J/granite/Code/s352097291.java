
import java.util.Scanner;

public class s352097291{
    public static void main(String[] args) {
        // Declare a character array 'c' to store the input string and 'ans' to store the result
        char c[] = new char[11];
        char ans[] = new char[11];
        
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read a string input from the user
        sc.nextLine().getChars(0, 10, c, 0);
        
        // Iterate through each character of the input string until the null terminator is encountered
        for (int i = 0; c[i]!= '\0'; i++) {
            // If the current character is not 'B', append it to the 'ans' string
            if (c[i]!= 'B') {
                ans[i] = c[i];
            } 
            // If the current character is 'B', remove the last character from 'ans' (if it exists)
            else {
                ans[i - 1] = '\0';
            }
        }
        
        // Print the resulting string after processing the input
        System.out.println(ans);
    }
}
