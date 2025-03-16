
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Initialize a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);

        // Read the first integer input from the user and store it in a variable named 'n'
        int n = sc.nextInt();

        // Allocate an integer array of size 'n' and name it 'nums'
        int[] nums = new int[n];

        // Use a for loop to read 'n' integers from the user and store them in the 'nums' array
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Initialize variables for minimum absolute value, count of negative numbers, and sum of absolute values
        int min = Integer.MAX_VALUE;
        int countNegatives = 0;
        long sum = 0;

        // Use a for-each loop to iterate through each number in the 'nums' array
        for (int num : nums) {
            // Calculate the absolute value of the current number and store it in a variable named 'abs'
            int abs = Math.abs(num);

            // Update the sum of absolute values by adding the absolute value to it
            sum += abs;

            // Update the minimum absolute value by finding the minimum of the current absolute value and the minimum absolute value
            min = Math.min(min, abs);

            // If the current number is negative, increment the count of negative numbers
            if (num < 0) {
                countNegatives++;
            }
        }

        // Print the output based on the parity of the count of negative numbers
        System.out.println(countNegatives % 2 == 0 ? sum : sum - (min*2));
    }
}