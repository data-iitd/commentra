
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare a variable to hold the input string
        String s;
        // Read input from the user
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();

        // Initialize a counter for consecutive valid characters and a slice to hold counts
        int count = 0;
        int[] counter = new int[0];

        // If the input string is empty, exit the function
        if (s.equals("")) {
            return;
        }

        // Start the counter with an initial value of 0
        counter[0] = 0;
        // Split the input string into a slice of individual characters
        String[] li = s.split("");

        // Iterate over each character in the slice
        for (String s : li) {
            // Check if the character is one of the valid DNA bases
            if (s.equals("A") || s.equals("C") || s.equals("G") || s.equals("T")) {
                // Increment the count for consecutive valid characters
                count++;
            } else {
                // If an invalid character is encountered, store the current count
                counter[counter.length] = count;
                // Reset the count for the next sequence
                count = 0;
            }
        }

        // Append the count of the last sequence of valid characters
        counter[counter.length] = count;
        // Sort the counts to find the maximum consecutive valid characters
        java.util.Arrays.sort(counter);
        // Print the maximum count of consecutive valid characters
        System.out.println(counter[counter.length - 1]);
    }
}

