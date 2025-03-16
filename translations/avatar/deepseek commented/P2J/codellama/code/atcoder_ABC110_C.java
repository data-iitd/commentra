
import java.util.Scanner;
// Import the Scanner class for input

import java.util.Collections;
// Import the Collections class for specialized container datatypes

import java.util.ArrayList;
// Import the ArrayList class for dynamic arrays

import java.util.HashMap;
// Import the HashMap class for hash tables

public class Solution {
    // Define the Solution class
    public static void main(String[] args) {
        // Define the main function to get input and print the result
        Scanner sc = new Scanner(System.in);
        // Create a Scanner object for input
        String s = sc.nextLine();
        // Get input for s from the user
        String t = sc.nextLine();
        // Get input for t from the user
        System.out.println(run(s, t));
        // Call the run function with s and t as arguments and print the result
    }

    public static String run(String s, String t) {
        // Define the run function that takes two arguments, s and t
        ArrayList<Integer> ss = new ArrayList<Integer>();
        // Create an ArrayList object for s
        for (int i = 0; i < s.length(); i++) {
            // Iterate over the characters of s
            int c = s.charAt(i);
            // Get the character at index i
            if (ss.contains(c)) {
                // If the ArrayList already contains the character
                int index = ss.indexOf(c);
                // Get the index of the character in the ArrayList
                ss.set(index, ss.get(index) + 1);
                // Increment the value at the index
            } else {
                // If the ArrayList does not contain the character
                ss.add(c);
                // Add the character to the ArrayList
            }
        }
        // Sort the ArrayList
        Collections.sort(ss);
        // Sort the ArrayList
        ArrayList<Integer> tt = new ArrayList<Integer>();
        // Create an ArrayList object for t
        for (int i = 0; i < t.length(); i++) {
            // Iterate over the characters of t
            int c = t.charAt(i);
            // Get the character at index i
            if (tt.contains(c)) {
                // If the ArrayList already contains the character
                int index = tt.indexOf(c);
                // Get the index of the character in the ArrayList
                tt.set(index, tt.get(index) + 1);
                // Increment the value at the index
            } else {
                // If the ArrayList does not contain the character
                tt.add(c);
                // Add the character to the ArrayList
            }
        }
        // Sort the ArrayList
        Collections.sort(tt);
        // Sort the ArrayList
        if (ss.equals(tt)) {
            // Check if the ArrayLists are equal
            return "Yes";
        } else {
            // If not equal, return "No"
            return "No";
        }
    }
}

