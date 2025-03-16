
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize an empty string variable 's' to store the input DNA sequence
        String s = "";

        // Read the input DNA sequence from the standard input using Scanner class
        Scanner scanner = new Scanner(System.in);
        s = scanner.nextLine();

        // Initialize a counter variable 'count' to keep track of the number of nucleotides (A, C, G, T) in the current nucleotide sequence
        // and a slice 'counter' to store the count of nucleotides in each sub-sequence between non-nucleotide characters
        int count = 0;
        int[] counter = new int[0];

        // Check if the input DNA sequence is empty or not
        if (s.equals("")) {
            // If the input DNA sequence is empty, return without doing anything
            return;
        }

        // Initialize the first element of the 'counter' slice with an initial count of 0
        counter[0] = 0;

        // Split the input DNA sequence into a slice 'li' of individual nucleotides using String.split() function
        String[] li = s.split("");

        // Iterate through each nucleotide in the 'li' slice using a for loop
        for (String s : li) {
            // Check if the current nucleotide is a valid nucleotide (A, C, G, T) or not
            if (s.equals("A") || s.equals("C") || s.equals("G") || s.equals("T")) {
                // If the current nucleotide is a valid nucleotide, increment the 'count' variable
                count++;
            } else {
                // If the current nucleotide is not a valid nucleotide, append the current count to the 'counter' slice and reset the 'count' variable to 0
                counter = append(counter, count);
                count = 0;
            }
        }

        // Append the final count of nucleotides in the last sub-sequence to the 'counter' slice
        counter = append(counter, count);

        // Sort the 'counter' slice in ascending order using Arrays.sort() function
        Arrays.sort(counter);

        // Print the last element of the sorted 'counter' slice, which represents the maximum count of nucleotides in any sub-sequence
        System.out.println(counter[counter.length - 1]);
    }

    // Function to append an element to the end of a slice
    public static int[] append(int[] slice, int element) {
        // Create a new slice with a length one greater than the input slice
        int[] newSlice = new int[slice.length + 1];

        // Copy the elements of the input slice to the new slice
        for (int i = 0; i < slice.length; i++) {
            newSlice[i] = slice[i];
        }

        // Set the last element of the new slice to the input element
        newSlice[newSlice.length - 1] = element;

        // Return the new slice
        return newSlice;
    }
}

