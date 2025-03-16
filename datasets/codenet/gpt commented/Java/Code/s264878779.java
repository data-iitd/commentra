import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the input string which represents a number
        String s = sc.next();
        
        // Get the length of the input string
        int n = s.length();
        
        // Initialize a variable to hold the final answer (sum of all possible sums)
        long ans = 0;
        
        // Loop through all possible combinations of '+' placements using bit masking
        for(int mask = 0 ; mask < 1<<(n - 1) ; mask++) {
            // Initialize a variable to hold the sum of the current combination
            long sum = 0;
            
            // Start building the expression with the first character of the string
            String x = "" + s.charAt(0);
            
            // Iterate through the characters of the string to determine where to place '+'
            for(int i = 0 ; i < n - 1 ; i++) {
                // Check if the current bit in the mask is set (indicating a '+' should be added)
                if((mask & (1 << i)) >= 1) {
                    // Append '+' and the next character to the expression
                    x += "+" + s.charAt(i + 1);
                } else {
                    // Append the next character without a '+' to the expression
                    x += s.charAt(i + 1);
                }
            }
            
            // Split the constructed expression into individual numbers based on the '+' delimiter
            String[] split = x.split("\\+");
            
            // Calculate the sum of the individual numbers in the current expression
            for(int i = 0 ; i < split.length ; i++) {
                sum += Long.valueOf(split[i]);
            }
            
            // Add the calculated sum of the current expression to the total answer
            ans += sum;
        }
        
        // Output the final answer which is the sum of all possible sums
        System.out.println(ans);
    }
}
