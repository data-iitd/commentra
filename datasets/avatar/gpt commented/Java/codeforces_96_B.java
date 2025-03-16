import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner(System.in);
        
        // Read a long integer from user input
        long number = in.nextLong();
        
        // Initialize variables to store the result and the current value
        long ans = -1, value = 0;
        
        // Initialize a mask variable starting from 2
        int mask = 2;
        
        // Loop until the current value is less than the input number
        while (value < number) {
            // Convert the current mask to a binary string and remove the leading '1'
            String s = Integer.toBinaryString(mask++).substring(1);
            
            // Initialize a counter for zeros in the binary string
            int zeros = 0;
            
            // Count the number of '0's in the binary string
            for (char c : s.toCharArray()) {
                if (c == '0') zeros++;
            }
            
            // If the number of zeros is not equal to the number of ones, skip to the next iteration
            if (zeros != s.length() - zeros) continue;
            
            // Replace '0's with '4's and '1's with '7's to form a new number
            s = s.replace('0', '4');
            s = s.replace('1', '7');
            
            // Parse the modified string as a long integer
            value = Long.parseLong(s);
        }
        
        // Print the final value that meets the condition
        System.out.println(value);
    }
}
