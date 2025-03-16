
package main;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the length of the input list
        int len = sc.nextInt();

        // Read the input list from standard input
        int[] l = new int[len];
        for (int i = 0; i < len; i++) {
            l[i] = sc.nextInt();
        }

        // Calculate and print the minimum of the three patterns
        System.out.println(min(pattern1(l), pattern2(l), pattern3(l)));
    }

    // Function to calculate the first pattern
    public static int pattern1(int[] l) {
        // Calculate the value of n using the given formula
        int n = (l[0] * l[3]) + (l[1] * l[4]);

        // Return the value of n
        return n;
    }

    // Function to calculate the second pattern
    public static int pattern2(int[] l) {
        // Calculate the maximum of l[3] and l[4]
        int maxNum = max(l[3], l[4]);

        // Calculate the value of n using the given formula
        int n = 2 * l[2] * maxNum;

        // Return the value of n
        return n;
    }

    // Function to calculate the third pattern
    public static int pattern3(int[] l) {
        // Calculate the minimum of l[3] and l[4]
        int minNum = min(l[3], l[4]);

        // Calculate the value of n using the given formula
        int n = 2 * l[2] * minNum + doch(l);

        // Return the value of n
        return n;
    }

    // Function to find the minimum of a list of numbers
    public static int min(int... nums) {
        // If the list is empty, panic with an error message
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument.");
        }

        // Initialize the minimum value as the first number in the list
        int res = nums[0];

        // Iterate through the list and update the minimum value if necessary
        for (int i = 0; i < nums.length; i++) {
            res = Math.min(res, nums[i]);
        }

        // Return the minimum value
        return res;
    }

    // Function to find the maximum of a list of numbers
    public static int max(int... nums) {
        // If the list is empty, panic with an error message
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument.");
        }

        // Initialize the maximum value as the first number in the list
        int res = nums[0];

        // Iterate through the list and update the maximum value if necessary
        for (int i = 0; i < nums.length; i++) {
            res = Math.max(res, nums[i]);
        }

        // Return the maximum value
        return res;
    }

    // Helper function to calculate the difference between the larger and smaller of two numbers
    public static int doch(int[] l) {
        // If l[3] is greater than l[4], return the product of l[0] and the difference between l[3] and l[4]
        if (l[3] > l[4]) {
            return l[0] * (l[3] - l[4]);
        } else {
            // Otherwise, return the product of l[1] and the difference between l[4] and l[3]
            return l[1] * (l[4] - l[3]);
        }
    }
}

