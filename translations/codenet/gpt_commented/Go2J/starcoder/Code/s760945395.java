package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Loop to iterate 5 times
        for (int i = 0; i < 5; i++) {
            int a; // Declare a variable 'a' to store user input
            Scanner sc = new Scanner(System.in);
            a = sc.nextInt(); // Read an integer input from the user and store it in 'a'

            // Check if the input value is zero
            if (a == 0) {
                // Print the current iteration index + 1 if the input is zero
                System.out.println(i + 1);
            }
        }
    }
}

