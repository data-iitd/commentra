
// AOJ 2601: Evacuation Route
// 2017.11.26 bal4u@uu

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int w = Integer.parseInt(line[0]); // Width of the evacuation route
        int[] a = new int[w+1]; // Array to hold the values of the evacuation route
        int[] b = new int[w+1]; // Array to hold the computed values for the evacuation route
        int ans = 0; // Initialize answer and flags
        int f = 0;
        int close = 0;
        int k;

        // Read the evacuation route values
        line = br.readLine().split(" ");
        for (int i = 1; i <= w; i++) {
            a[i] = Integer.parseInt(line[i-1]); // Read the next integer into array a
            if (!a[i]) f |= 1; // Set flag if value is zero
            else if (a[i] < 0) f |= 2; // Set flag if value is negative
            else ans += a[i]; // Accumulate positive values into ans
        }

        // Check for special cases: no positive values or only zeros
        if (!ans || !(f & 1)) { System.out.println("0"); return; }
        // If there are no negative values, print the total sum
        if (!(f & 2)) { System.out.println(ans); return; }

        // Calculate the minimum distance to the closest zero from the left
        for (close = 0, f = 0, k = 1; k <= w; k++) {
            if (!a[k]) close = Integer.MAX_VALUE, f = -1; // Reset close distance if zero is found
            else if (a[k] < 0) {
                // Update close distance if a negative value is found
                if (f < 0 || close - (k-f) > -a[k]) close = -a[k], f = k;
            } else {
                // Calculate the distance to the closest zero for positive values
                if (f < 0) b[k] = Integer.MAX_VALUE; // If no zero found, set to infinity
                else {
                    k = close - (k-f); if (k < 0) k = 0; // Calculate distance
                    b[k] = k; // Store the distance in array b
                }
            }
        }

        // Calculate the minimum distance to the closest zero from the right
        for (close = 0, f = w, k = w; k >= 1; k--) {
            if (!a[k]) close = Integer.MAX_VALUE, f = -1; // Reset close distance if zero is found
            else if (a[k] < 0) {
                // Update close distance if a negative value is found
                if (f < 0 || close - (f-k) > -a[k]) close = -a[k], f = k;
            } else {
                // Calculate the distance to the closest zero for positive values
                if (f < 0) b[k] = Integer.MAX_VALUE; // If no zero found, set to infinity
                else {
                    k = close - (f-k); if (k < 0) k = 0; // Calculate distance
                    if (k > b[k]) b[k] = k; // Update if the new distance is smaller
                }
            }
        }

        // Calculate the final answer based on the minimum distances
        for (ans = 0, k = 1; k <= w; k++) {
            if (a[k] > 0) {
                // Add the minimum of the positive value or the calculated distance
                if (b[k] > a[k]) ans += a[k];
                else             ans += b[k];
            }
        }
        
        // Print the final answer
        System.out.println(ans);
    }
}

