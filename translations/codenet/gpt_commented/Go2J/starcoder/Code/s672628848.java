package main;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare five integer variables to hold input values
        int a, b, c, d, e;

        // Read five integers from standard input
        Scanner in = new Scanner(System.in);
        a = in.nextInt();
        b = in.nextInt();
        c = in.nextInt();
        d = in.nextInt();
        e = in.nextInt();

        // Create a slice containing the input integers
        int[] al = new int[]{a, b, c, d, e};

        // Iterate over the slice to find the first occurrence of zero
        for (int n = 0; n < al.length; n++) {
            // Check if the current element is zero
            if (al[n] == 0) {
                // Print the index (1-based) of the first zero found and exit the loop
                System.out.println(n + 1);
                break;
            }
        }
    }
}

