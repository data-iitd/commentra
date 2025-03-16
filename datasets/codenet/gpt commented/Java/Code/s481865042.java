import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read a string input from the user
        String s = sc.next();
        
        // Read a long integer input from the user
        long k = sc.nextLong();
        
        // Create a StringBuffer to build the resulting string
        StringBuffer sb = new StringBuffer();
        
        // Iterate through each character in the input string
        for (int i = 0; i < s.length(); i++) {
            // Calculate how many steps are needed to change the current character to 'a'
            // If the steps needed are less than or equal to k and the character is not 'a'
            if ((26 - (s.charAt(i) - 'a')) <= k && s.charAt(i) != 'a') {
                // Deduct the steps from k
                k -= 26 - (s.charAt(i) - 'a');
                // Append 'a' to the result
                sb.append('a');
            } else {
                // If not changing to 'a', append the original character to the result
                sb.append(s.charAt(i));
            }
        }
        
        // If there are remaining steps (k > 0) after processing all characters
        if (k > 0) {
            // Get the last character of the current result
            char t = sb.charAt(s.length() - 1);
            // Remove the last character from the result
            sb.delete(s.length() - 1, s.length());
            // Append a new character that is calculated based on the remaining k
            sb.append((char) ('a' + (t - 'a' + k) % 26));
        }
        
        // Print the final result
        System.out.println(sb);
    }
}
