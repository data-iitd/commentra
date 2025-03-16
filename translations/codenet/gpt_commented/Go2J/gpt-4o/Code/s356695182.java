import java.util.Scanner;

public class Main {
    // Initialize a new scanner to read from standard input
    private static final Scanner sc = new Scanner(System.in);

    // nextInt reads the next integer from standard input
    private static int nextInt() {
        return sc.nextInt(); // Read the next integer
    }

    // scanNums reads a specified number of integers from standard input and returns them as an array
    private static int[] scanNums(int len) {
        int[] nums = new int[len]; // Create an array to hold the integers
        for (int i = 0; i < len; i++) {
            nums[i] = nextInt(); // Read an integer and store it in the array
        }
        return nums; // Return the array of integers
    }

    // pattern1 calculates a specific pattern based on the first five integers in the array
    private static int pattern1(int[] l) {
        return (l[0] * l[3]) + (l[1] * l[4]); // Calculate the result based on the formula
    }

    // pattern2 calculates another pattern based on the maximum of the last two integers
    private static int pattern2(int[] l) {
        return 2 * l[2] * max(l[3], l[4]); // Calculate the result using the maximum value
    }

    // pattern3 calculates a third pattern that combines the minimum value and a function call
    private static int pattern3(int[] l) {
        return 2 * l[2] * min(l[3], l[4]) + doch(l); // Calculate the result using the minimum value and doch function
    }

    // min returns the minimum value from a variable number of integer arguments
    private static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument."); // Throw exception if no arguments are provided
        }
        int res = nums[0]; // Initialize the result with the first argument
        for (int num : nums) {
            res = Math.min(res, num); // Update the result to the minimum value
        }
        return res; // Return the minimum value
    }

    // max returns the maximum value from a variable number of integer arguments
    private static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument."); // Throw exception if no arguments are provided
        }
        int res = nums[0]; // Initialize the result with the first argument
        for (int num : nums) {
            res = Math.max(res, num); // Update the result to the maximum value
        }
        return res; // Return the maximum value
    }

    // doch calculates a value based on the difference between the last two integers in the array
    private static int doch(int[] l) {
        if (l[3] > l[4]) {
            return l[0] * (l[3] - l[4]); // Return the product if the fourth integer is greater
        } else {
            return l[1] * (l[4] - l[3]); // Return the product if the fifth integer is greater
        }
    }

    // main function where the program execution begins
    public static void main(String[] args) {
        int len = 5; // Define the number of integers to read
        int[] l = scanNums(len); // Read the integers into an array
        // Print the minimum value from the three calculated patterns
        System.out.println(min(pattern1(l), pattern2(l), pattern3(l)));
    }
}
// <END-OF-CODE>
