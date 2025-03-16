
import java.util.Scanner;

public class atcoder_ABC136_B{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input from the user
        int N = scanner.nextInt();
        
        // Initialize the variable to keep track of the power of 10
        int i = 1;
        
        // Initialize the answer variable to accumulate the result
        int ans = 0;
        
        // Loop to calculate the contribution of each range of numbers defined by powers of 10
        while (Math.pow(10, i) <= N) {
            // Add the count of numbers in the current range (10^(i-1) to 10^i)
            ans += (int) Math.pow(10, i) - (int) Math.pow(10, i - 1);
            
            // Increment i by 2 to move to the next range (skipping even powers)
            i += 2;
        }
        
        // Add the count of numbers from the last valid power of 10 to N
        ans += Math.max(0, N - (int) Math.pow(10, i - 1) + 1);
        
        // Print the final result
        System.out.println(ans);
    }
}

// Entry point of the program
