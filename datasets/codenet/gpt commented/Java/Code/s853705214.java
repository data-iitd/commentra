import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements in the array
        int n = sc.nextInt();
        // Initialize an array to hold the integers
        int[] nums = new int[n];

        // Populate the array with integers from user input
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Initialize variables to track the minimum absolute value, count of negative numbers, and the sum of absolute values
        int min = Integer.MAX_VALUE;
        int countNegatives = 0;
        long sum = 0;

        // Iterate through the array to calculate the required values
        for (int num : nums) {
            // Calculate the absolute value of the current number
            int abs = Math.abs(num);
            // Add the absolute value to the sum
            sum += abs;
            // Update the minimum absolute value found
            min = Math.min(min, abs);
            // Count how many negative numbers are in the array
            if (num < 0) {
                countNegatives++;
            }
        }

        // Print the result based on the count of negative numbers
        // If the count of negatives is even, print the sum; if odd, subtract twice the minimum absolute value from the sum
        System.out.println(countNegatives % 2 == 0 ? sum : sum - (min * 2));
    }
}
