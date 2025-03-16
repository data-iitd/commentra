
import java.util.*;

public class s554610878{
    // Constants for buffer sizes
    private static final int INITIAL_BUF_SIZE = 10000;
    private static final int MAX_BUF_SIZE = 1000000;

    // Global variables for scanner and modulus
    private static Scanner sc = new Scanner(System.in);
    private static int mod = 1000000007;

    public static void main(String[] args) {
        // Array representing the days of the week
        String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

        // Get the input day as a string
        String s = getString();
        int index = -1; // Initialize index to -1 to indicate not found

        // Search for the input day in the week array
        for (int i = 0; i < week.length; i++) {
            if (s.equals(week[i])) {
                index = i; // Update index if the day is found
                break;
            }
        }

        // Calculate and print the number of days until the next Sunday
        System.out.println(7 - index);
    }

    // Function to read an integer from input
    private static int getInt() {
        sc.useDelimiter(null); // Use null delimiter to read the entire line
        int i = Integer.parseInt(sc.nextLine()); // Parse the input as an integer
        sc.useDelimiter(" "); // Reset the delimiter to space
        return i; // Return the integer value
    }

    // Function to read a string from input
    private static String getString() {
        sc.useDelimiter(null); // Use null delimiter to read the entire line
        String s = sc.nextLine(); // Read the input as a string
        sc.useDelimiter(" "); // Reset the delimiter to space
        return s; // Return the string value
    }

    // Function to compute the absolute value of an integer
    private static int abs(int a) {
        return (int) Math.abs(a); // Use Math.abs to get the absolute value
    }

    // Function to compute p raised to the power of q
    private static int pow(int p, int q) {
        return (int) Math.pow(p, q); // Use Math.pow for exponentiation
    }

    // Function to find the minimum value among given integers
    private static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument."); // Throw an exception if no arguments are provided
        }
        int res = nums[0]; // Initialize result with the first number
        for (int i = 0; i < nums.length; i++) {
            res = Math.min(res, nums[i]); // Update result with the minimum value
        }
        return res; // Return the minimum value
    }

    // Function to find the maximum value among given integers
    private static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument."); // Throw an exception if no arguments are provided
        }
        int res = nums[0]; // Initialize result with the first number
        for (int i = 0; i < nums.length; i++) {
            res = Math.max(res, nums[i]); // Update result with the maximum value
        }
        return res; // Return the maximum value
    }

    // Function to check if a string exists in a slice of strings
    private static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true; // Return true if the string is found
            }
        }
        return false; // Return false if the string is not found
    }

    // Function to print an array of integers
    private static void printIntArray(int[] array) {
        System.out.println(Arrays.toString(array)); // Print the array as a string
    }

    // Function to calculate the modulus of x with respect to the defined mod
    private static int calcMod(int x) {
        return x % mod; // Return the result of x modulo mod
    }
}

