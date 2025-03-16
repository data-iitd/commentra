
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Set log flags to show the file name and line number for log messages
        System.setProperty("java.util.logging.SimpleFormatter.format",
                "%1$tF %1$tT %4$s %2$s %5$s%6$s%n");

        // Initialize a new scanner to read input
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        // Read two integers from input
        int x = sc.nextInt();
        int y = sc.nextInt();

        // Initialize variables to store the category indices of x and y
        int xt = 0;
        int yt = 0;

        // Define a 2D array where each sub-array represents a category of numbers
        int[][] a = {
                {1, 3, 5, 7, 8, 10, 12},
                {4, 6, 9, 11},
                {2}
        };

        // Iterate through the categories to find the indices of x and y
        for (int i = 0; i < a.length; i++) {
            for (int n : a[i]) {
                // Check if the current number matches x
                if (x == n) {
                    xt = i; // Store the category index for x
                }
                // Check if the current number matches y
                if (y == n) {
                    yt = i; // Store the category index for y
                }
            }
        }

        // Compare the category indices of x and y and print the result
        if (xt == yt) {
            System.out.println("Yes"); // x and y belong to the same category
        } else {
            System.out.println("No"); // x and y belong to different categories
        }
    }

    // max returns the maximum of two integers
    public static int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }

    // scanner struct to handle buffered input reading
    public static class scanner {
        private BufferedReader r; // Buffered reader
        private char[] buf; // Buffer to hold read data
        private int p; // Current position in the buffer

        // newScanner initializes a new scanner with a specified buffer size
        public scanner(BufferedReader r) {
            this.r = r;
        }

        // next reads the next token from the input
        public String next() {
            pre(); // Ensure there's data to read
            int start = p; // Mark the start position
            for (; p < buf.length; p++) {
                if (buf[p] == ' ') { // Stop at space
                    break;
                }
            }
            String result = new String(buf, start, p - start); // Extract the token
            p++; // Move past the space
            return result; // Return the token
        }

        // nextLine reads the next line from the input
        public String nextLine() {
            pre(); // Ensure there's data to read
            int start = p; // Mark the start position
            p = buf.length; // Move to the end of the buffer
            return new String(buf, start, p - start); // Return the line
        }

        // nextInt reads the next integer from the input
        public int nextInt() {
            return Integer.parseInt(next()); // Convert the next token to an integer
        }

        // pre checks if more data needs to be read into the buffer
        public void pre() {
            if (p >= buf.length) { // If the current position is at or beyond the buffer length
                readLine(); // Read a new line into the buffer
                p = 0; // Reset the position to the start of the buffer
            }
        }

        // readLine reads a full line from the input into the buffer
        public void readLine() {
            buf = new char[0]; // Clear the buffer
            for (; ; ) {
                char[] l; // Declare a char array to hold the line
                boolean p; // Declare a boolean to hold the line continuation status
                try {
                    l = r.readLine().toCharArray(); // Read a line
                    p = r.ready(); // Check if the line is continued
                } catch (Exception e) {
                    throw new RuntimeException(e); // Panic on error
                }
                buf = concat(buf, l); // Append the line to the buffer
                if (!p) { // If the line is not continued
                    break; // Exit the loop
                }
            }
        }

        // concat concatenates two char arrays
        public static char[] concat(char[] a, char[] b) {
            char[] c = new char[a.length + b.length]; // Create a new char array to hold the concatenated arrays
            System.arraycopy(a, 0, c, 0, a.length); // Copy the first array into the new array
            System.arraycopy(b, 0, c, a.length, b.length); // Copy the second array into the new array
            return c; // Return the concatenated array
        }
    }
}

