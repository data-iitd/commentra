
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

// mainFn is the main function of the program
public class s068639994{
    public static void mainFn() {
        // Get the number of elements in the input array
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        // Get the input array
        int[] ls = new int[n];
        for (int i = 0; i < n; i++) {
            ls[i] = scanner.nextInt();
        }
        // Create a reversed copy of the input array
        int[] lsRev = Arrays.copyOf(ls, n);
        // Sort the input array in ascending order
        Arrays.sort(ls);
        // Sort the reversed copy of the array in descending order
        Arrays.sort(lsRev);
        // Reverse the reversed copy of the array
        for (int i = 0; i < n; i++) {
            lsRev[i] = -lsRev[i];
        }

        // Initialize the answer variable
        int ans = 0;
        // Iterate through all pairs of elements in the array
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Find the minimum and maximum elements of the current pair
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                // Calculate the difference between the maximum and minimum elements
                int x = q - p;
                int y = q + p;
                // Find the indices of the elements greater than x and less than y in the sorted array and reversed array respectively
                int l = Arrays.binarySearch(ls, x);
                if (l < 0) {
                    l = -l - 1;
                }
                int r = Arrays.binarySearch(lsRev, -y);
                if (r < 0) {
                    r = -r - 1;
                }
                // Calculate the sum of the difference between the indices of the greater elements in the sorted array and reversed array
                int sum = r - l;
                // Check if the current pair lies within the range [l, r]
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                // Ensure that the sum is not negative
                sum = Math.max(0, sum);
                // Add the sum to the answer variable
                ans += sum;
            }
        }
        // Divide the answer by 3 and print it
        ans /= 3;
        System.out.println(ans);
    }

    // main is the entry point of the program
    public static void main(String[] args) {
        // Call the main function
        mainFn();
    }
}

// -----------------------------------------

// min returns the minimum of two integers
public static int min(int a, int b) {
    return a < b? a : b;
}

// max returns the maximum of two integers
public static int max(int a, int b) {
    return a > b? a : b;
}

// -----------------------------------------

// getInt reads an integer from the standard input
public static int getInt() {
    Scanner scanner = new Scanner(System.in);
    // Convert the input string to an integer and return it
    return scanner.nextInt();
}

// getIntSlice reads an array of integers from the standard input
public static int[] getIntSlice(int n) {
    // Allocate memory for the array
    int[] is = new int[n];
    // Read each element of the array from the standard input
    for (int i = 0; i < n; i++) {
        is[i] = getInt();
    }
    // Return the array
    return is;
}

// getString reads a string from the standard input
public static String getString() {
    Scanner scanner = new Scanner(System.in);
    // Return the input string
    return scanner.next();
}

// puts writes the given arguments to the standard output, followed by a newline character
public static void puts(Object... a) {
    // Write the arguments to the standard output
    for (Object o : a) {
        System.out.print(o);
    }
    System.out.println();
}

// -----------------------------------------

// 