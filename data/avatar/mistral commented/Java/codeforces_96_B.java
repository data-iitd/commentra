
import java.util.Scanner ;

public class Main {
    // Initialize scanner to read input from standard input
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // Read a long number as input
        long number = in.nextLong();

        // Initialize variables for answer and current value
        long ans = -1, value = 0;

        // Initialize mask variable for binary number manipulation
        int mask = 2;

        // Main loop to find the answer
        while (value < number) {
            // Convert mask to binary string and remove leading '1'
            String s = Integer.toBinaryString(mask++).substring(1);

            // Count the number of zeros in the binary string
            int zeros = 0;
            for (char c : s.toCharArray())
                if (c == '0') zeros++;

            // If the number of zeros is not equal to the length of the binary string minus the number of zeros, continue to the next iteration
            if (zeros != s.length() - zeros) continue;

            // Replace all zeros with '4' and all ones with '7' in the binary string
            s = s.replace('0', '4').replace('1', '7');

            // Convert the modified binary string back to a long number and update the value variable
            value = Long.parseLong(s);
        }

        // Print the answer
        System.out.println(value);
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further clarification or modification.