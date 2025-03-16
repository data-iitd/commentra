package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare a variable to hold the input string
        String s;

        // Read input from the user and store it in the variable's'
        Scanner scanner = new Scanner(System.in);
        s = scanner.next();

        // Initialize the base price
        int price = 700;

        // Iterate over each character in the input string
        for (int i = 0; i < s.length(); i++) {
            // Check if the character is 'o'
            if (s.charAt(i) == 'o') {
                // If it is 'o', increase the price by 100
                price += 100;
            }
        }

        // Print the final price after processing the input string
        System.out.println(price);
    }
}

