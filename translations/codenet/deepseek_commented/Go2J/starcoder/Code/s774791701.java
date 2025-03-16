
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a string variable to store user input
        String s;
        // Read input from the user and store it in the variable `s`
        Scanner scanner = new Scanner(System.in);
        s = scanner.next();

        // Initialize the price variable with a starting value of 700
        int price = 700;
        // Loop through each character in the string `s`
        for (int i = 0; i < s.length(); i++) {
            // Check if the current character is 'o'
            if (s.charAt(i) == 'o') {
                // If the character is 'o', add 100 to the price
                price += 100;
            }
        }
        // Print the final value of the price
        System.out.println(price);
    }
}

