import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream.
        Scanner sc = new Scanner(System.in);
        // Read the number of elements in the array.
        int n = sc.nextInt();
        // Initialize an array to store the integers.
        int[] nums = new int[n];

        // Populate the array with n integers read from the input.
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Initialize variables to store the minimum absolute value, count of negative numbers, and sum of absolute values.
        int min = Integer.MAX_VALUE;
        int countNegatives = 0;
        long sum = 0;

        // Iterate over each element in the array.
        for (int num : nums) {
            // Calculate the absolute value of the current number and add it to the sum.
            int abs = Math.abs(num);
            sum += abs;
            // Update the minimum absolute value encountered so far.
            min = Math.min(min, abs);
            // If the current number is negative, increment the count of negative numbers.
            if (num < 0) {
                countNegatives++;
            }
        }

        // Print the result based on whether the number of negative integers is even or odd.
        // If even, print the sum of absolute values. If odd, print the sum minus twice the smallest absolute value.
        System.out.println(countNegatives % 2 == 0 ? sum : sum - (min*2));
    }
}
