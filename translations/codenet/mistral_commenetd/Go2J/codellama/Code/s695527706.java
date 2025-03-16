// Package main is the entry point of the program
package main

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two variables, n and s
        int n;
        String s;

        // Read the input from the standard input
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        s = scanner.next();

        // Print the result of the strings.Count function
        System.out.println(s.length() - s.replace("ABC", "").length());
    }
}

// This is the end of the code
