
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize a buffered reader for reading input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Read the values of h and n from input
        int h = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        int a = 0; // Initialize a variable to accumulate the sum of integers

        // Loop to read n integers and accumulate their sum
        for (int i = 0; i < n; i++) {
            a += Integer.parseInt(br.readLine());
        }

        // Check if the accumulated sum is less than h
        if (h > a) {
            // If h is greater than the sum, print "No"
            System.out.println("No");
        } else {
            // Otherwise, print "Yes"
            System.out.println("Yes");
        }
    }
}

