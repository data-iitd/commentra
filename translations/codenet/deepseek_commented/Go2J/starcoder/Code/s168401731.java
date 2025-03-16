package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // Check if command-line arguments are provided for file input/output.
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        if (args.length >= 1) {
            inputStream = new FileInputStream(args[0]);
        }
        if (args.length >= 2) {
            outputStream = new FileOutputStream(args[1]);
        }

        // Read the number of integers to process.
        Scanner scanner = new Scanner(inputStream);
        int n = scanner.nextInt();
        scanner.close();

        // Initialize the answer to "second".
        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (a % 2 == 1) {
                ans = "first";
                break;
            }
        }
        // Print the result based on the condition.
        outputStream.write((ans + "\n").getBytes());
        outputStream.close();
    }
}

