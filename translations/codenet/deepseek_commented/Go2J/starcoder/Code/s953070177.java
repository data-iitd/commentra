package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read the number of elements.
        int n = scanner.nextInt();

        // Initialize a slice to store the elements and a sum variable.
        int[] aa = new int[n+2];
        int sum = 0;

        // Read the elements into the slice and calculate the sum of absolute differences.
        for (int i = 0; i < n; i++) {
            aa[i+1] = scanner.nextInt();
            sum += Math.abs(aa[i+1] - aa[i]);
        }
        sum += Math.abs(aa[n+1] - aa[n]);

        // Calculate and print the differences for each element.
        for (int i = 1; i < n+1; i++) {
            int ans = sum - Math.abs(aa[i+1]-aa[i]) - Math.abs(aa[i]-aa[i-1]) + Math.abs(aa[i+1]-aa[i-1]);
            writer.write(ans + "\n");
        }

        // Flush the writer to ensure all output is written to the output stream.
        writer.flush();
    }
}

