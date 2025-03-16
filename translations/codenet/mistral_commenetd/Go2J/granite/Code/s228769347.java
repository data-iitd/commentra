
// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

public class s228769347{
    // s228769347 function to solve the problem
    public static void main(String[] args) throws IOException {
        // Initializing standard input and output file pointers
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // If input file and output file are provided as command line arguments
        if (args.length > 0) {
            // Open the input file
            br = new BufferedReader(new FileReader(args[0]));

            // If output file is provided, create it
            if (args.length > 1) {
                bw = new BufferedWriter(new FileWriter(args[1]));
            }
        }

        // Read the number of elements in the array
        int n = Integer.parseInt(br.readLine());

        // Initialize a list to store the elements
        List<Integer> ll = new ArrayList<>();

        // Read the elements of the array
        String[] input = br.readLine().split(" ");
        for (String s : input) {
            ll.add(Integer.parseInt(s));
        }

        // Sort the list in ascending order
        Collections.sort(ll);

        // Initialize the answer variable to 0
        int ans = 0;

        // Iterate through all possible pairs of elements
        for (int i = 0; i < n - 2; i++) {
            // Iterate through all possible right pointers
            for (int j = i + 1; j < n - 1; j++) {
                // Initialize the left and right pointers for binary search
                int l = j + 1;
                int r = n;

                // Binary search to find the index of the element greater than the sum of the current pair
                while (l < r) {
                    int m = (l + r) / 2;
                    if (ll.get(m) < ll.get(i) + ll.get(j)) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }

                // Update the answer variable
                ans += l - (j + 1);
            }
        }

        // Write the answer to the output file
        bw.write(String.valueOf(ans));
        bw.newLine();

        // Close the input and output file pointers
        br.close();
        bw.close();
    }
}

// "

