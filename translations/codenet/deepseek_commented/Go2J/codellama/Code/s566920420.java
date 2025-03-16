package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable 'a' to store the user input
        int a;

        // Read an integer input from the user and store it in 'a'
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();

        // Print the result of the expression 'a + a*a + a*a*a'
        System.out.println(a + a*a + a*a*a);
    }
}
