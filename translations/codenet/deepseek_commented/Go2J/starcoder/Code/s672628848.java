package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare five integer variables to hold input values
        int a, b, c, d, e;

        // Read five integers from the standard input and assign them to the variables
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();

        // Create a slice containing the five integers
        int[] al = new int[]{a, b, c, d, e};

        // Iterate over the slice using a for loop with the range keyword
        for (int n = 0; n < al.length; n++) {
            // Check if the current element is equal to 0
            if (al[n] == 0) {
                // Print the position of the element (1-based index) and break out of the loop
                System.out.println(n + 1);
                break;
            }
        }
    }
}

