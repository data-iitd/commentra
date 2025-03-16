
// Package main is the entry point of the program
package main;

import java.util.Scanner;

public class s695527706{
    public static void main(String[] args) {
        // Declare two variables, n and s
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();

        // Print the result of the strings.Count function
        System.out.println(countOccurrences(s, "ABC"));
    }

    public static int countOccurrences(String s, String sub) {
        // Initialize a variable to store the count of occurrences
        int count = 0;

        // Use a for loop to iterate through the string s
        for (int i = 0; i < s.length() - sub.length() + 1; i++) {
            // Use a substring method to extract a substring of length sub.length() starting from index i
            String substring = s.substring(i, i + sub.length());

            // Use the equals method to compare the substring with the string sub
            if (substring.equals(sub)) {
                // Increment the count variable if the substring matches the string sub
                count++;
            }
        }

        // Return the count variable
        return count;
    }
}

// This is the end of the code


