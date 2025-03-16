import java.util.*;  // Importing Java utilities
import java.io.*;  // Importing Java I/O
import java.math.*;  // Importing Java math

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Creating a Scanner object for reading input

        // Reading input values
        int q = sc.nextInt();
        int h = sc.nextInt();
        int s = sc.nextInt();
        int d = sc.nextInt();
        int n = sc.nextInt();

        // Calculating the best price for single liters
        int best1L = Math.min(q * 4, h * 2, s);

        // Calculating the best price for double liters
        int best2L = Math.min(d, best1L * 2);

        // Checking if the quantity n is even or odd and printing the total cost accordingly
        if (n % 2 == 0) {
            System.out.println(best2L * (n / 2));
        } else {
            System.out.println(best2L * (n / 2) + best1L);
        }
    }
}

