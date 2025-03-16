
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

// Define a custom type 'pair' for sorting
class pair implements Comparable<pair> {
    int index;
    int p1, p2;

    public pair(int index, int p1, int p2) {
        this.index = index;
        this.p1 = p1;
        this.p2 = p2;
    }

    @Override
    public int compareTo(pair o) {
        return this.index - o.index;
    }
}

// Define a slice type 'pairs' for sorting 'pair' type
class pairs implements Comparable<pairs> {
    pair[] pairs;

    public pairs(pair[] pairs) {
        this.pairs = pairs;
    }

    @Override
    public int compareTo(pairs o) {
        return this.pairs[0].index - o.pairs[0].index;
    }
}

// Define a custom type 'Int64Slice' for sorting int64 slices
class Int64Slice implements Comparable<Int64Slice> {
    long[] slice;

    public Int64Slice(long[] slice) {
        this.slice = slice;
    }

    @Override
    public int compareTo(Int64Slice o) {
        for (int i = 0; i < this.slice.length; i++) {
            if (this.slice[i] < o.slice[i]) {
                return -1;
            } else if (this.slice[i] > o.slice[i]) {
                return 1;
            }
        }
        return 0;
    }
}

// Define some constants
final int initialBufSize = 1024; // Initial buffer size for bufio.NewScanner
final int maxBufSize = 1048576; // Maximum buffer size for bufio.NewScanner
final long INF = 100000000; // Infinite value for some calculations

// Initialize some global variables
Scanner scanner = new Scanner(System.in); // Input scanner
PrintWriter writer = new PrintWriter(System.out); // Output writer
int[] di = {-1, 0, 1, 0}; // Direction vectors for 2D grid traversal
int[] dj = {0, -1, 0, 1}; // Direction vectors for 2D grid traversal

// s684610901 function
public class s684610901{
    public static void main(String[] args) {
        // Initialize the buffer with the given size
        scanner = new Scanner(System.in).useDelimiter("\\A");
        scanner.useLocale(Locale.ENGLISH);

        // Read input A, B, and C
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        // Check if C is within the range of A and B
        if (C >= A && C <= B) {
            System.out.println("Yes"); // Print "Yes" if condition is true
        } else {
            System.out.println("No");  // Print "No" if condition is false
        }
    }
}

// Helper functions for reading input
boolean nextPermutation(List<Integer> x) {
    // Implementation of next permutation algorithm for sorting
}

int[][] doubleAry(int h, int w, int init) {
    // Function to initialize a 2D int array with given dimensions and initial value
}

boolean aryEq(int[] a, int[] b) {
    // Function to check if two arrays are equal
}

int[] clone(int[] n) {
    // Function to clone a slice
}

void write(String s) {
    // Function to write a string to the output writer
}

void print() {
    // Function to flush the output writer
}

String readLine() {
    // Function to read a line from the input scanner
}

int readInt() {
    // Function to read an integer from the input scanner
}

float readFloat() {
    // Function to read a float from the input scanner
}

char[] readRunes() {
    // Function to read a rune slice from the input scanner
}

String readString() {
    // Function to read a string from the input scanner
}

String[] readStrings() {
    // Function to read a string slice from the input scanner
}

int s2i(String s) {
    // Function to convert a string to an integer
}

String i2s(int i) {
    // Function to convert an integer to a string
}

int abs(int i) {
    // Function to get the absolute value of an integer
}

int max(int... i) {
    // Function to get the maximum value from a slice of integers
}

int min(int... i) {
    // Function to get the minimum value from a slice of integers
}

int sum(int[] i) {
    // Function to get the sum of elements in a slice of integers
}

String[] split(String s) {
    // Function to split a string into a slice of strings using space as delimiter
}

int[] strAry2intAry(String[] strs) {
    // Function to convert a slice of strings to a slice of integers
}

String[] intAry2strAry(int[] nums) {
    // Function to convert a slice of integers to a slice of strings
}

String ary2str(String[] strs) {
    // Function to join a slice of strings into a single string using space as delimiter
}

int[] reverse(int[] res) {
    // Function to reverse the order of elements in a slice
}

String[] reverseStr(String[] res) {
    // Function to reverse the order of elements in a slice of strings
}

void ini(int[] res, int init) {
    // Function to initialize the first element of a slice with a given value
}

// Uncomment the following code if you want to use regexp package
// void regexpExample() {
//     // Your code here!
//     String str = "13:20";
//     Pattern r = Pattern.compile("(\\d+):(\\d+)");
//     Matcher m = r.matcher(str);
//     if (m.find()) {
//         System.out.println(m.group(1));
//         System.out.println(m.group(2));
//     }
// }

// Define a custom type 'Country' with gold, silver, and bronze fields
// class Country {
//     int gold;
//     int silver;
//     int blonze;
// }

// Function to sort a slice of 'Country' based on bronze, silver, and gold fields in that order
// Country[] stableSortExample() {
//     // Your code here!
// }

// Translate the above Java code to Python and end with comment "