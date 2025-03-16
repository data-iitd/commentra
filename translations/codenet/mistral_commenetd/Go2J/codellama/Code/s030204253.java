// Package declaration for the main Java program
package main;

// Import the Scanner class for reading input from the standard input
import java.util.Scanner;

// Initialize an integer variable 'n' and read its value from the standard input
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Create an array 'a' of 'n' float64 elements
        float[] a = new float[n];

        // Read 'n' float64 values from the standard input and assign them to the array 'a'
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextFloat();
        }

        // Iterate through the array 'a' 'n-1' times and sort it using the 'Arrays.sort' function
        for (int i = 0; i+1 < n; i++) {
            Arrays.sort(a);
        }

        // Initialize an empty array 'na' of float64
        float[] na = new float[0];

        // Iterate through the array 'a' starting from index 2 and append its elements to the array 'na'
        for (int j = 2; j < a.length; j++) {
            na = Arrays.copyOf(na, na.length + 1);
            na[na.length - 1] = a[j];
        }

        // Reassign the value of the array 'a' with the array 'na' and the first two elements being the average of the first two elements of the original array 'a'
        na = Arrays.copyOf(na, na.length + 2);
        na[na.length - 2] = (a[0] + a[1]) / 2;
        a = na;

        // Print the first element of the sorted array 'a' to the standard output
        System.out.println(a[0]);
    }
}

