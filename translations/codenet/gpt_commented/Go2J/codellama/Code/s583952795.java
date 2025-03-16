
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        // Read two integers N and K from input
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        // Convert the number N from base 10 to base K
        String s = TenToN(N, K);
        // Print the length of the resulting string
        writer.println(s.length());
        writer.flush();
    }

    // Function to convert a number from base 10 to base N
    public static String TenToN(int number, int n) {
        String s = ""; // String to hold the result
        int tmp = number; // Temporary variable to hold the current number
        while (true) {
            // Prepend the remainder of the division to the result string
            s = i2s(tmp % n) + s;
            if (tmp < n) { // If the temporary number is less than the base, exit the loop
                break;
            }
            tmp /= n; // Divide the temporary number by the base
        }
        return s; // Return the converted string
    }

    // Function to convert a string to an integer
    public static int s2i(String s) {
        int intVal = Integer.parseInt(s); // Convert string to integer
        return intVal; // Return the integer value
    }

    // Function to convert an integer to a string
    public static String i2s(int i) {
        String strVal = Integer.toString(i); // Convert integer to string
        return strVal; // Return the string value
    }

    // Function to convert a string to a float
    public static double s2f(String s) {
        double floatVal = Double.parseDouble(s); // Convert string to float
        return floatVal; // Return the float value
    }

    // Function to calculate the sum of a slice of integers
    public static int sum(int[] i) {
        int sum = 0; // Initialize sum
        for (int val : i) {
            sum += val; // Add each value to the sum
        }
        return sum; // Return the total sum
    }

    // Function to split a string into a slice of strings
    public static String[] split(String s) {
        return s.split(" "); // Split the string by whitespace and return the slice
    }

    // Function to convert a slice of strings to a slice of integers
    public static int[] strAry2intAry(String[] strs) {
        int[] ret = new int[strs.length]; // Initialize the result slice
        for (int i = 0; i < strs.length; i++) {
            int intVal = Integer.parseInt(strs[i]); // Convert each string to an integer
            ret[i] = intVal; // Append the integer to the result slice
        }
        return ret; // Return the slice of integers
    }

    // Function to convert a slice of integers to a slice of strings
    public static String[] intAry2strAry(int[] nums) {
        String[] ret = new String[nums.length]; // Initialize the result slice
        for (int i = 0; i < nums.length; i++) {
            String strVal = Integer.toString(nums[i]); // Convert each integer to a string
            ret[i] = strVal; // Append the string to the result slice
        }
        return ret; // Return the slice of strings
    }

    // Function to join a slice of strings into a single string
    public static String ary2str(String[] strs) {
        return String.join(" ", strs); // Join the strings with a space and return
    }

    // Function to reverse a slice of integers
    public static int[] reverse(int[] res) {
        for (int i = 0, j = res.length - 1; i < j; i++, j--) {
            res[i] = res[j]; // Swap elements to reverse the slice
            res[j] = res[i];
        }
        return res; // Return the reversed slice
    }

    // Function to initialize a slice with a given value
    public static void initalize(int[] res, int init) {
        if (res.length == 0) {
            return; // Do nothing if the slice is empty
        }
        res[0] = init; // Set the first element to the initial value
        for (int i = 0; i < res.length; i++) {
            System.arraycopy(res, 0, res, i, i); // Copy elements to shift them
        }
    }

    // Example function for regular expressions (commented out)
    // public static void regexpExample() {
    //     // Your code here!
    //     String str = "13:20";
    //     Pattern r = Pattern.compile("(\\d+):(\\d+)");
    //     System.out.println(r.matcher(str).find());
    // }

    // Struct to hold medal counts for a country (commented out)
    // public static class Country {
    //     int gold;
    //     int silver;
    //     int blonze;
    // }

    // // Example function for stable sorting (commented out)
    // public static Country[] stableSortExample() {
    //     Country[] country = {
    //             new Country(1, 2, 3),
    //             new Country(1, 2, 3),
    //             new Country(1, 3, 2),
    //             new Country(1, 3, 3),
    //     };
    //     Arrays.sort(country, (o1, o2) -> o1.blonze - o2.blonze);
    //     Arrays.sort(country, (o1, o2) -> o1.silver - o2.silver);
    //     Arrays.sort(country, (o1, o2) -> o1.gold - o2.gold);
    //     return country;
    // }

    // 