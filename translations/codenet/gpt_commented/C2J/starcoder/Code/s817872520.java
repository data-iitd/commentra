// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int w, i, k, f, close, ans; // Declare variables for width, indices, flags, close distance, and answer

        // Read the width of the evacuation route
        w = Integer.parseInt(br.readLine());
        // Read the evacuation route values
        String[] s = br.readLine().split(" ");

        // Initialize answer and flags, and process the route values
        for (ans = 0, f = 0, i = 1; i <= w; i++) {
            k = Integer.parseInt(s[i-1]); // Read the next integer into array a
            if (!k) f |= 1; // Set flag if value is zero
            else if (k < 0) f |= 2; // Set flag if value is negative
            else ans += k; // Accumulate positive values into ans
        }
        
        // Check for special cases: no positive values or only zeros
        if (!ans ||!(f & 1)) { System.out.println("0"); return; }
        // If there are no negative values, print the total sum
        if (!(f & 2)) { System.out.println(ans); return; }

        // Calculate the minimum distance to the closest zero from the left
        for (close = 0, f = 0, i = 1; i <= w; i++) {
            if (!k) close = Integer.MAX_VALUE, f = -1; // Reset close distance if zero is found
            else if (k < 0) {
                // Update close distance if a negative value is found
                if (f < 0 || close - (i-f) > -k) close = -k, f = i;
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
            if (!k) close = Integer.MAX_VALUE, f = -1; // Reset close distance if zero is found
            else if (k < 0) {
                // Update close distance if a negative value is found
                if (f < 0 || close - (f-i) > -k) close = -k, f = i;
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
        for (ans = 0, i = 1; i <= w; i++) {
            if (k > 0) {
                // Add the minimum of the positive value or the calculated distance
                if (b[i] > k) ans += k;
                else             ans += b[i];
            }
        }
        
        // Print the final answer
        System.out.println(ans);
    }
}

