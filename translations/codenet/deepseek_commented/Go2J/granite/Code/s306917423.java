
import java.util.Scanner;

public class s306917423{
    public static void main(String[] args) {
        // Initialize a string variable to store the input
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        // Initialize a variable to count the number of '1's in the input string
        int ans = 0;
        // Iterate over each character in the string `s`
        for (char c : s.toCharArray()) {
            // Check if the character is '1'
            if (c == '1') {
                // Increment the count of '1's
                ans++;
            }
        }
        // Print the count of '1's to the standard output
        System.out.println(ans);
    }
}
