import java.util.Scanner;

public class Main {
    // Initialize a scanner for reading input from stdin
    private static final Scanner sc = new Scanner(System.in);

    // Function to read an integer from standard input
    private static int nextInt() {
        return sc.nextInt(); // Read the next integer from standard input
    }

    // Function to read multiple integers from standard input
    private static int[] scanNums(int len) {
        // Initialize an array to store the numbers
        int[] nums = new int[len];

        // Read each number from standard input and store it in the array
        for (int i = 0; i < len; i++) {
            nums[i] = nextInt(); // Read a number from standard input
        }

        // Return the array of numbers
        return nums;
    }

    // Function to calculate the first pattern
    private static int pattern1(int[] l) {
        // Calculate the value of n using the given formula
        return (l[0] * l[3]) + (l[1] * l[4]);
    }

    // Function to calculate the second pattern
    private static int pattern2(int[] l) {
        // Calculate the maximum of l[3] and l[4]
        int maxNum = Math.max(l[3], l[4]);

        // Calculate the value of n using the given formula
        return 2 * l[2] * maxNum;
    }

    // Function to calculate the third pattern
    private static int pattern3(int[] l) {
        // Calculate the minimum of l[3] and l[4]
        int minNum = Math.min(l[3], l[4]);

        // Calculate the value of n using the given formula
        return 2 * l[2] * minNum + doch(l);
    }

    // Helper function to calculate the difference between the larger and smaller of two numbers
    private static int doch(int[] l) {
        // If l[3] is greater than l[4], return the product of l[0] and the difference between l[3] and l[4]
        if (l[3] > l[4]) {
            return l[0] * (l[3] - l[4]);
        } else {
            // Otherwise, return the product of l[1] and the difference between l[4] and l[3]
            return l[1] * (l[4] - l[3]);
        }
    }

    // Function to find the minimum of a list of numbers
    private static int min(int... nums) {
        // If the list is empty, throw an exception
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument.");
        }

        // Initialize the minimum value as the first number in the list
        int res = nums[0];

        // Iterate through the list and update the minimum value if necessary
        for (int num : nums) {
            res = Math.min(res, num);
        }

        // Return the minimum value
        return res;
    }

    // Main function to read input and call the pattern functions
    public static void main(String[] args) {
        // Read the length of the input list
        int len = 5;

        // Read the input list from standard input
        int[] l = scanNums(len);

        // Calculate and print the minimum of the three patterns
        System.out.println(min(pattern1(l), pattern2(l), pattern3(l)));
    }
}
// <END-OF-CODE>
