
import java.util.Scanner;

public class s306917423{
    public static void main(String[] args) {
        // Declare a variable to hold the input string
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        // Initialize a counter to keep track of the number of '1's in the string
        int ans = 0;
        
        // Iterate over each character in the input string
        for (char c : s.toCharArray()) {
            // Check if the current character is '1'
            if (c == '1') {
                // Increment the counter if '1' is found
                ans++;
            }
        }
        
        // Print the total count of '1's found in the input string
        System.out.println(ans);
    }
}
