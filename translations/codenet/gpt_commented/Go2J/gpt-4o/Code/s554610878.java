import java.util.Scanner;

public class Main {
    // Constants for modulus
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        // Array representing the days of the week
        String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
        
        // Get the input day as a string
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
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

    // Function to compute the absolute value of an integer
    public static int abs(int a) {
        return Math.abs(a); // Use Math.abs to get the absolute value
    }

    // Function to compute p raised to the power of q
    public static int pow(int p, int q) {
        return (int) Math.pow(p, q); // Use Math.pow for exponentiation
    }

    // Function to find the minimum value among given integers
    public static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument."); // Throw exception if no arguments are provided
        }
        int res = nums[0]; // Initialize result with the first number
        for (int num : nums) {
            res = Math.min(res, num); // Update result with the minimum value
        }
        return res; // Return the minimum value
    }

    // Function to find the maximum value among given integers
    public static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument."); // Throw exception if no arguments are provided
        }
        int res = nums[0]; // Initialize result with the first number
        for (int num : nums) {
            res = Math.max(res, num); // Update result with the maximum value
        }
        return res; // Return the maximum value
    }

    // Function to check if a string exists in a slice of strings
    public static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true; // Return true if the string is found
            }
        }
        return false; // Return false if the string is not found
    }

    // Function to print an array of integers
    public static void printIntArray(int[] array) {
        StringBuilder strArray = new StringBuilder();
        for (int i = 0; i < array.length; i++) {
            strArray.append(array[i]);
            if (i < array.length - 1) {
                strArray.append(", "); // Add a comma between elements
            }
        }
        System.out.println(strArray.toString()); // Print the string representation
    }

    // Function to calculate the modulus of x with respect to the defined mod
    public static int calcMod(int x) {
        return x % MOD; // Return the result of x modulo mod
    }
}

// <END-OF-CODE>
