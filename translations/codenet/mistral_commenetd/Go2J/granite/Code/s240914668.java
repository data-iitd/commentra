
// Package main is the entry point of the program
package main;

import java.util.*;
import java.io.*;

public class s240914668{
    public static void main(String[] args) throws Exception {
        // Initialize scanner, reader, and writer
        Scanner sc = new Scanner(System.in);
        BufferedReader rdr = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wt = new PrintWriter(System.out);

        // Read a single word from the standard input
        String next = sc.next();

        // Read an integer from the standard input
        int nextInt = sc.nextInt();

        // Read float64 from the standard input
        double nextFloat64 = sc.nextDouble();

        // Read n integers from the standard input
        int[] nextInts = new int[nextInt];
        for (int i = 0; i < nextInts.length; i++) {
            nextInts[i] = sc.nextInt();
        }

        // Read n float64 from the standard input
        double[] nextFloat64s = new double[nextInt];
        for (int i = 0; i < nextFloat64s.length; i++) {
            nextFloat64s[i] = sc.nextDouble();
        }

        // Read a megabyte-sized string from the standard input
        StringBuilder sb = new StringBuilder();
        String line;
        while ((line = rdr.readLine())!= null) {
            sb.append(line);
        }
        String nextMega = sb.toString();

        // Print a formatted string to the standard output
        System.out.printf("Hello, %s!\n", "World");

        // Print a single line to the standard output
        System.out.println("Hello, World!");

        // Close the scanner, reader, and writer
        sc.close();
        rdr.close();
        wt.close();
    }
}

