
package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare variables to hold the lengths of the two bases and the height
        int a, b, h;

        // Read input values for the two bases (a and b) and the height (h) from the user
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        h = scanner.nextInt();

        // Calculate the area of the trapezoid using the formula: Area = (a + b) * h / 2
        // and print the result to the console
        System.out.println((a + b) * h / 2);
    }
}
