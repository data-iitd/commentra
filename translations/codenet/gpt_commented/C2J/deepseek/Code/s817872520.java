import java.io.*;
import java.util.*;

public class EvacuationRoute {
    static final int INF = 0x5fffffff; // Define a constant for infinity
    static int[] a = new int[100002]; // Array to hold the values of the evacuation route
    static int[] b = new int[100002]; // Array to hold the computed values for the evacuation route
    static char[] buf = new char[700002]; // Buffer for input
    static int p = 0; // Pointer to traverse the buffer

    // Function to read an integer from the input buffer
    static int getint() {
        int n = 0; // Initialize the integer to store the result
        // Check for negative sign
        if (buf[p] == '-') {
            p++; // Move to the next character
            while (buf[p] >= '0') n = (n << 3) + (n << 1) + (buf[p++] & 0xf); // Convert characters to integer
            return -n; // Return the negative integer
        }
        // Convert characters to integer for positive numbers
        while (buf[p] >= '0') n = (n << 3) + (n << 1) + (buf[p++] & 0xf);
        return n; // Return the positive integer
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int w = Integer.parseInt(tokenizer.nextToken()); // Read the width of the evacuation route
        reader.read(buf); // Read the evacuation route values into the buffer

        int ans = 0, f = 0; // Declare variables for answer and flags

        // Initialize answer and flags, and process the route values
        for (int i = 1; i <= w; i++) {
            a[i] = getint(); // Read the next integer into array a
            if (a[i] == 0) f |= 1; // Set flag if value is zero
            else if (a[i] < 0) f |= 2; // Set flag if value is negative
            else ans += a[i]; // Accumulate positive values into ans
        }

        // Check for special cases: no positive values or only zeros
        if (ans == 0 || (f & 1) == 0) { System.out.println(0); return; }
        // If there are no negative values, print the total sum
        if ((f & 2) == 0) { System.out.println(ans); return; }

        // Calculate the minimum distance to the closest zero from the left
        int close = 0; // Initialize close distance
        for (int i = 1; i <= w; i++) {
            if (a[i] == 0) close = INF; // Reset close distance if zero is found
            else if (a[i] < 0) {
                // Update close distance if a negative value is found
                if (close == INF || close - (i - close) > -a[i]) close = -a[i];
            } else {
                // Calculate the distance to the closest zero for positive values
                if (close == INF) b[i] = INF; // If no zero found, set to infinity
                else {
                    int k = close - (i - close); if (k < 0) k = 0; // Calculate distance
                    b[i] = k; // Store the distance in array b
                }
            }
        }

        // Calculate the minimum distance to the closest zero from the right
        close = 0; // Initialize close distance
        for (int i = w; i >= 1; i--) {
            if (a[i] == 0) close = INF; // Reset close distance if zero is found
            else if (a[i] < 0) {
                // Update close distance if a negative value is found
                if (close == INF || close - (close - i) > -a[i]) close = -a[i];
            } else {
                // Calculate the distance to the closest zero for positive values
                if (close == INF) b[i] = INF; // If no zero found, set to infinity
                else {
                    int k = close - (close - i); if (k < 0) k = 0; // Calculate distance
                    if (k > b[i]) b[i] = k; // Update if the new distance is smaller
                }
            }
        }

        // Calculate the final answer based on the minimum distances
        ans = 0; // Initialize answer
        for (int i = 1; i <= w; i++) {
            if (a[i] > 0) {
                // Add the minimum of the positive value or the calculated distance
                if (b[i] > a[i]) ans += a[i];
                else ans += b[i];
            }
        }

        // Print the final answer
        System.out.println(ans);
    }
}
