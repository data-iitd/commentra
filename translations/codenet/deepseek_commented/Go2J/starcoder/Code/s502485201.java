package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Declare integer variables to hold input values
        int r, d, x;

        // Read three integers from standard input
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt();
        d = sc.nextInt();
        x = sc.nextInt();

        // Start a loop that will run 10 times
        for (int i = 0; i < 10; i++) {
            // Update the value of x using the formula r*x - d
            x = r * x - d;
            // Print the updated value of x
            System.out.println(x);
        }
    }
}

