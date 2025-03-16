import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the main string from user input
        String s = scanner.nextLine();
        
        // Read the number of subsequent strings to process
        int n = Integer.parseInt(scanner.nextLine());
        
        // Initialize the answer variable to accumulate results
        int ans = 0;
        
        // Loop through each of the n strings provided by the user
        for (int i = 0; i < n; i++) {
            // Read the current string
            String x = scanner.nextLine();
            
            // Initialize counters for characters matching the first and second characters of x
            int a = 0, b = 0;
            
            // Loop through each character in the main string s
            for (char j : s.toCharArray()) {
                // If the character matches the first character of x, increment counter a
                if (j == x.charAt(0)) {
                    a++;
                }
                // If the character matches the second character of x, increment counter b
                else if (j == x.charAt(1)) {
                    b++;
                } else {
                    // If a character does not match either, add the minimum of a and b to ans
                    ans += Math.min(a, b);
                    // Reset counters a and b for the next segment
                    a = 0;
                    b = 0;
                }
            }
            
            // After finishing the loop, add the minimum of a and b to ans for the last segment
            ans += Math.min(a, b);
        }
        
        // Print the final accumulated answer
        System.out.println(ans);
    }
}
