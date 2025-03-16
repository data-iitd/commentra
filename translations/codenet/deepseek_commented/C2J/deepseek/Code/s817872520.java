import java.io.*;
import java.util.*;

public class Main {
    static final int INF = 0x5fffffff; // Define the maximum possible integer value
    static int[] a = new int[100002]; // Declare array 'a' to store integers
    static int[] b = new int[100002]; // Declare array 'b' to store evacuation routes

    static byte[] buf = new byte[700002]; // Buffer for reading input
    static int p = 0; // Pointer for parsing

    // Function to read an integer from the input buffer
    static int getint() throws IOException {
        int n = 0;
        boolean isNegative = false;
        byte c = 0;
        while ((c = (byte)System.in.read()) <= ' ') ; // Skip whitespace
        if (c == '-') { // Check if the number is negative
            isNegative = true;
            c = (byte)System.in.read();
        }
        while (c >= '0') n = (n << 3) + (n << 1) + (c & 0xf); // Parse the number
        return isNegative ? -n : n;
    }

    public static void main(String[] args) throws IOException {
        int w, i, k, f, close, ans; // Declare variables to store input, indices, and results

        w = getint(); // Read the width of the array and store it in 'w'
        System.in.read(buf, 0, 10); // Read the input line into the buffer
        for (ans = 0, f = 0, i = 1; i <= w; i++) { // Initialize variables and start parsing the input
            a[i] = k = getint();
            if (k == 0) f |= 1; // Set flag if zero is found
            else if (k < 0) f |= 2; // Set flag if negative number is found
            else ans += k; // Add to the sum if positive number
        }
        if (ans == 0 || (f & 1) == 0) { System.out.println("0"); return; } // If no positive numbers or zero found, output 0
        if ((f & 2) == 0) { System.out.println(ans); return; } // If no negative numbers, output the sum of positive numbers

        // Calculate the minimum evacuation routes
        for (close = 0, f = 0, i = 1; i <= w; i++) { // First pass from left to right
            if (a[i] == 0) close = INF; // Reset if zero is found
            else if (a[i] < 0) {
                if (f < 0 || close - (i - f) > -a[i]) close = -a[i]; // Update the closest negative number
            } else {
                if (f < 0) b[i] = INF; // If no negative number found yet, set to INF
                else {
                    k = close - (i - f); if (k < 0) k = 0; // Calculate the evacuation route
                    b[i] = k;
                }
            }
        }

        for (close = 0, f = w, i = w; i >= 1; i--) { // Second pass from right to left
            if (a[i] == 0) close = INF; // Reset if zero is found
            else if (a[i] < 0) {
                if (f < 0 || close - (f - i) > -a[i]) close = -a[i]; // Update the closest negative number
            } else {
                if (f < 0) b[i] = INF; // If no negative number found yet, set to INF
                else {
                    k = close - (f - i); if (k < 0) k = 0; // Calculate the evacuation route
                    if (k > b[i]) b[i] = k; // Update if a better route is found
                }
            }
        }

        for (ans = 0, i = 1; i <= w; i++) { // Calculate the total evacuation route
            if (a[i] > 0) {
                if (b[i] > a[i]) ans += a[i]; // Add the minimum of b[i] and a[i]
                else ans += b[i];
            }
        }
        System.out.println(ans); // Output the final result
    }
}
