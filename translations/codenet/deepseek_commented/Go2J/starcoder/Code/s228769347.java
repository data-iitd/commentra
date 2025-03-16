package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // Check if file paths are provided as command-line arguments.
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        if (args.length >= 1) {
            inputStream = new FileInputStream(args[0]);
        }
        if (args.length >= 2) {
            outputStream = new FileOutputStream(args[1]);
        }

        // Read the number of elements.
        Scanner scanner = new Scanner(inputStream);
        int n = scanner.nextInt();
        scanner.close();

        // Read n integers into the slice ll.
        int[] ll = new int[n];
        Scanner scanner2 = new Scanner(inputStream);
        for (int i = 0; i < n; i++) {
            ll[i] = scanner2.nextInt();
        }
        scanner2.close();

        // Sort the slice ll.
        Arrays.sort(ll);

        // Initialize the answer variable.
        int ans = 0;

        // Iterate through possible triplets (i, j, m) where i < j < m.
        for (int i = 0; i < n-2; i++) {
            for (int j = i + 1; j < n-1; j++) {
                int l = j + 1;
                int r = n;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (ll[m] < ll[i]+ll[j]) {
                        l = m + 1;
                        continue;
                    }
                    r = m;
                }

                // Add the number of valid m's to the answer.
                ans += l - (j + 1);
            }
        }

        // Print the final answer to the standard output.
        OutputStreamWriter writer = new OutputStreamWriter(outputStream);
        writer.write(String.valueOf(ans) + "\n");
        writer.close();
    }
}

