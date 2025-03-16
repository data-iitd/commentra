// Import necessary packages
import java.util.*;
import java.io.*;

// Main class
public class Main {
    // Define some constants
    private static final int INITIAL_BUF_SIZE = 10000; // Initial buffer size
    private static final int MAX_BUF_SIZE = 100000000; // Maximum buffer size
    private static final int INF = 100000000; // Infinite value for some calculations

    // Main function
    public static void main(String[] args) throws IOException {
        // Initialize input and output
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read input A, B, and C
        long A = readInt(reader);
        long B = readInt(reader);
        long C = readInt(reader);

        // Check if C is within the range of A and B
        if (C >= A && C <= B) {
            writer.write("Yes\n"); // Print "Yes" if condition is true
        } else {
            writer.write("No\n");  // Print "No" if condition is false
        }

        // Flush the output writer
        writer.flush();
    }

    // Helper function to read an integer from input
    private static long readInt(BufferedReader reader) throws IOException {
        return Long.parseLong(reader.readLine().trim());
    }

    // Additional helper functions can be defined here as needed
    // For example, functions for reading strings, arrays, etc.

    // Function to get the absolute value of an integer
    private static long abs(long i) {
        return i < 0 ? -i : i;
    }

    // Function to get the maximum value from a list of integers
    private static long max(long... values) {
        return Arrays.stream(values).max().orElse(Long.MIN_VALUE);
    }

    // Function to get the minimum value from a list of integers
    private static long min(long... values) {
        return Arrays.stream(values).min().orElse(Long.MAX_VALUE);
    }

    // Function to get the sum of elements in an array of integers
    private static long sum(long[] array) {
        return Arrays.stream(array).sum();
    }

    // Function to split a string into an array of strings using space as delimiter
    private static String[] split(String s) {
        return s.split(" ");
    }

    // Function to convert a string array to a long array
    private static long[] strArrayToLongArray(String[] strs) {
        return Arrays.stream(strs).mapToLong(Long::parseLong).toArray();
    }

    // Function to convert a long array to a string array
    private static String[] longArrayToStrArray(long[] nums) {
        return Arrays.stream(nums).mapToObj(String::valueOf).toArray(String[]::new);
    }

    // Function to join a string array into a single string using space as delimiter
    private static String arrayToString(String[] strs) {
        return String.join(" ", strs);
    }

    // Function to reverse the order of elements in a long array
    private static long[] reverse(long[] array) {
        long[] reversed = new long[array.length];
        for (int i = 0; i < array.length; i++) {
            reversed[i] = array[array.length - 1 - i];
        }
        return reversed;
    }

    // Function to reverse the order of elements in a string array
    private static String[] reverseStr(String[] array) {
        String[] reversed = new String[array.length];
        for (int i = 0; i < array.length; i++) {
            reversed[i] = array[array.length - 1 - i];
        }
        return reversed;
    }
}

// <END-OF-CODE>
