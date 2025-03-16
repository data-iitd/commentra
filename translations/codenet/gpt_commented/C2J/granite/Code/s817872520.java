
// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class s817872520{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int w = Integer.parseInt(br.readLine()); // Read the width of the evacuation route
        String[] inputs = br.readLine().split(" "); // Read the evacuation route values
        int[] a = new int[w+1]; // Array to hold the values of the evacuation route
        int[] b = new int[w+1]; // Array to hold the computed values for the evacuation route
        int ans = 0, f = 0, i = 1, k = 0, close = 0; // Declare variables for answer, flags, indices, and close distance

        // Process the route values
        for (i = 1; i <= w; i++) {
            a[i] = k = Integer.parseInt(inputs[i-1]); // Read the next integer into array a
            if (k == 0) f |= 1; // Set flag if value is zero
            else if (k < 0) f |= 2; // Set flag if value is negative
            else ans += k; // Accumulate positive values into ans
        }

        // Check for special cases: no positive values or only zeros
        if (ans == 0 || (f & 1) == 0) { System.out.println(0); return; }
        // If there are no negative values, print the total sum
        if ((f & 2) == 0) { System.out.println(ans); return; }

        // Calculate the minimum distance to the closest zero from the left
        for (close = 0, f = 0, i = 1; i <= w; i++) {
            if (a[i] == 0) close = Integer.MAX_VALUE, f = -1; // Reset close distance if zero is found
            else if (a[i] < 0) {
                // Update close distance if a negative value is found
                if (f < 0 || close - (i-f) > -a[i]) close = -a[i], f = i;
            } else {
                // Calculate the distance to the closest zero for positive values
                if (f < 0) b[i] = Integer.MAX_VALUE; // If no zero found, set to infinity
                else {
                    k = close - (i-f); if (k < 0) k = 0; // Calculate distance
                    b[i] = k; // Store the distance in array b
                }
            }
        }

        // Calculate the minimum distance to the closest zero from the right
        for (close = 0, f = w, i = w; i >= 1; i--) {
            if (a[i] == 0) close = Integer.MAX_VALUE, f = -1; // Reset close distance if zero is found
            else if (a[i] < 0) {
                // Update close distance if a negative value is found
                if (f < 0 || close - (f-i) > -a[i]) close = -a[i], f = i;
            } else {
                // Calculate the distance to the closest zero for positive values
                if (f < 0) b[i] = Integer.MAX_VALUE; // If no zero found, set to infinity
                else {
                    k = close - (f-i); if (k < 0) k = 0; // Calculate distance
                    if (k > b[i]) b[i] = k; // Update if the new distance is smaller
                }
            }
        }

        // Calculate the final answer based on the minimum distances
        for (i = 1; i <= w; i++) {
            if (a[i] > 0) {
                // Add the minimum of the positive value or the calculated distance
                if (b[i] > a[i]) ans += a[i];
                else             ans += b[i];
            }
        }

        // Print the final answer
        System.out.println(ans);
    }
}

