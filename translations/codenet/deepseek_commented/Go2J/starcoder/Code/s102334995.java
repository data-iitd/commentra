
package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables a and b to store integers
        int a, b;
        
        // Read two integers from standard input and store them in a and b
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        // Print the product of a and b
        System.out.println(a * b);
        
        // Print the perimeter of a rectangle with sides a and b
        System.out.println((a + b) * 2);
    }
}

