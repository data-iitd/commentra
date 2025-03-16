
// Package main is the entry point of the program
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

// Define a custom type 'pair' for sorting
class pair {
    int index; // Index for sorting
    Object p1; // Two elements to be compared
    Object p2; // Two elements to be compared

    public pair(int index, Object p1, Object p2) {
        this.index = index;
        this.p1 = p1;
        this.p2 = p2;
    }
}

// Define a slice type 'pairs' for sorting 'pair' type
class pairs {
    List<pair> pairs;

    public pairs(List<pair> pairs) {
        this.pairs = pairs;
    }

    public int size() {
        return pairs.size();
    }

    public pair get(int i) {
        return pairs.get(i);
    }

    public void set(int i, pair p) {
        pairs.set(i, p);
    }
}

// Define a custom type 'Int64Slice' for sorting int64 slices
class Int64Slice {
    List<Long> slice;

    public Int64Slice(List<Long> slice) {
        this.slice = slice;
    }

    public int size() {
        return slice.size();
    }

    public long get(int i) {
        return slice.get(i);
    }

    public void set(int i, long v) {
        slice.set(i, v);
    }
}

// Define some constants
final int initialBufSize = 1e4; // Initial buffer size for bufio.NewScanner
final int maxBufSize = 1e8; // Maximum buffer size for bufio.NewScanner
final int INF = 1e8; // Infinite value for some calculations

// Initialize some global variables
Scanner scanner = new Scanner(System.in); // Input scanner
PrintWriter writer = new PrintWriter(System.out); // Output writer
int[] di = { -1, 0, 1, 0 }; // Direction vectors for 2D grid traversal
int[] dj = { 0, -1, 0, 1 }; // Direction vectors for 2D grid traversal

// Main function
public static void main(String[] args) {
    // Initialize the buffer with the given size
    byte[] buf = new byte[initialBufSize];
    scanner.useDelimiter("\\s+"); // Split input by words

    // Read input A, B, and C
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    int C = scanner.nextInt();

    // Check if C is within the range of A and B
    if (C >= A && C <= B) {
        writer.println("Yes"); // Print "Yes" if condition is true
    } else {
        writer.println("No"); // Print "No" if condition is false
    }

    writer.flush(); // Flush the output writer
}

// Helper functions for reading input
public static boolean NextPermutation(pairs x) {
    // Implementation of next permutation algorithm for sorting
}

public static long[][] doubleAry(int h, int w, long init) {
    // Function to initialize a 2D int64 array with given dimensions and initial value
}

public static boolean aryEq(long[] a, long[] b) {
    // Function to check if two arrays are equal
}

public static long[] clone(long[] n) {
    // Function to clone a slice
}

public static void write(String s) {
    // Function to write a string to the output writer
}

public static void print() {
    // Function to flush the output writer
}

public static String readLine() {
    // Function to read a line from the input scanner
}

public static int readInt() {
    // Function to read an integer from the input scanner
}

public static double readFloat() {
    // Function to read a float from the input scanner
}

public static char[] readRunes() {
    // Function to read a rune slice from the input scanner
}

public static String readString() {
    // Function to read a string from the input scanner
}

public static String[] readStrings() {
    // Function to read a string slice from the input scanner
}

public static int s2i(String s) {
    // Function to convert a string to an integer
}

public static String i2s(int i) {
    // Function to convert an integer to a string
}

public static int abs(int i) {
    // Function to get the absolute value of an integer
}

public static int max(int... a) {
    // Function to get the maximum value from a slice of integers
}

public static int min(int... a) {
    // Function to get the minimum value from a slice of integers
}

public static int sum(int[] i) {
    // Function to get the sum of elements in a slice of integers
}

public static String[] split(String s) {
    // Function to split a string into a slice of strings using space as delimiter
}

public static int[] strAry2intAry(String[] strs) {
    // Function to convert a slice of strings to a slice of integers
}

public static String[] intAry2strAry(int[] nums) {
    // Function to convert a slice of integers to a slice of strings
}

public static String ary2str(String[] strs) {
    // Function to join a slice of strings into a single string using space as delimiter
}

public static int[] reverse(int[] res) {
    // Function to reverse the order of elements in a slice
}

public static String[] reverseStr(String[] res) {
    // Function to reverse the order of elements in a slice of strings
}

public static void ini(int[] res, int init) {
    // Function to initialize the first element of a slice with a given value
}

// Uncomment the following code if you want to use regexp package
// public static void regexpExample() {
//     // Your code here!
//     String str = "13:20";
//     Pattern r = Pattern.compile("(\\d+):(\\d+)");
//     System.out.println(r.matcher(str).find());
// }

// Define a custom type 'Country' with gold, silver, and bronze fields
// class Country {
//     int gold;
//     int silver;
//     int blonze;

//     public Country(int gold, int silver, int blonze) {
//         this.gold = gold;
//         this.silver = silver;
//         this.blonze = blonze;
//     }
// }

// Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
// public static Country[] stableSortExample() {
//     // Your code here!
// }

