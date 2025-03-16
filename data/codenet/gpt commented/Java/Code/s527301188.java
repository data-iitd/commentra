import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        // Create a BufferedReader to read input from the standard input stream
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        // Read a line of input, split it into strings based on spaces
        String[] strs = reader.readLine().split(" ");
        
        // Initialize an integer array to store the numbers and a variable to track the top of the stack
        int[] nums = new int[strs.length];
        int top = 0;

        // Iterate through each string in the input
        for (int i = 0; i < strs.length; i++) {
            // Check the first character of the string to determine if it's an operator or a number
            switch (strs[i].charAt(0)) {
                case '+':
                    // If the operator is '+', pop the top two numbers, add them, and push the result back
                    top--;
                    nums[top - 1] = nums[top - 1] + nums[top];
                    break;
                case '-':
                    // If the operator is '-', pop the top two numbers, subtract them, and push the result back
                    top--;
                    nums[top - 1] = nums[top - 1] - nums[top];
                    break;
                case '*':
                    // If the operator is '*', pop the top two numbers, multiply them, and push the result back
                    top--;
                    nums[top - 1] = nums[top - 1] * nums[top];
                    break;
                default:
                    // If it's not an operator, parse the string as an integer and push it onto the stack
                    nums[top] = Integer.parseInt(strs[i]);
                    top++;
                    break;
            }
            // Uncomment the following line to see the current state of the nums array after each operation
            // System.out.println(Arrays.toString(nums));
        }

        // Output the final result, which is the only number left in the stack
        System.out.println(nums[0]);
    }
}
