import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class EvacuationRoute {
    static final int INF = 0x5fffffff; // Define a constant for infinity
    static int[] a = new int[100002]; // Array to hold the values of the evacuation route
    static int[] b = new int[100002]; // Array to hold the computed values for the evacuation route

    // Function to read an integer from the input
    static int getInt(BufferedReader reader) throws IOException {
        int n = 0; // Initialize the integer to store the result
        int c = reader.read();
        // Check for negative sign
        if (c == '-') {
            while ((c = reader.read()) >= '0') {
                n = (n << 3) + (n << 1) + (c & 0xf); // Convert characters to integer
            }
            return -n; // Return the negative integer
        }
        // Convert characters to integer for positive numbers
        while (c >= '0') {
            n = (n << 3) + (n << 1) + (c & 0xf);
            c = reader.read();
        }
        return n; // Return the positive integer
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int w = getInt(reader); // Read the width of the evacuation route
        // Read the evacuation route values
        String[] input = reader.readLine().trim().split(" ");
        
        int ans = 0, f = 0; // Initialize answer and flags
        for (int i = 1; i <= w; i++) {
            a[i] = Integer.parseInt(input[i - 1]); // Read the next integer into array a
            if (a[i] == 0) f |= 1; // Set flag if value is zero
            else if (a[i] < 0) f |= 2; // Set flag if value is negative
            else ans += a[i]; // Accumulate positive values into ans
        }

        // Check for special cases: no positive values or only zeros
        if (ans == 0 || (f & 1) == 0) {
            System.out.println("0");
            return;
        }
        // If there are no negative values, print the total sum
        if ((f & 2) == 0) {
            System.out.println(ans);
            return;
        }

        // Calculate the minimum distance to the closest zero from the left
        int close = 0;
        f = 0;
        for (int i = 1; i <= w; i++) {
            if (a[i] == 0) {
                close = INF;
                f = -1; // Reset close distance if zero is found
            } else if (a[i] < 0) {
                // Update close distance if a negative value is found
                if (f < 0 || close - (i - f) > -a[i]) {
                    close = -a[i];
                    f = i;
                }
            } else {
                // Calculate the distance to the closest zero for positive values
                if (f < 0) b[i] = INF; // If no zero found, set to infinity
                else {
                    int k = close - (i - f);
                    if (k < 0) k = 0; // Calculate distance
                    b[i] = k; // Store the distance in array b
                }
            }
        }

        // Calculate the minimum distance to the closest zero from the right
        close = 0;
        f = w;
        for (int i = w; i >= 1; i--) {
            if (a[i] == 0) {
                close = INF;
                f = -1; // Reset close distance if zero is found
            } else if (a[i] < 0) {
                // Update close distance if a negative value is found
                if (f < 0 || close - (f - i) > -a[i]) {
                    close = -a[i];
                    f = i;
                }
            } else {
                // Calculate the distance to the closest zero for positive values
                if (f < 0) b[i] = INF; // If no zero found, set to infinity
                else {
                    int k = close - (f - i);
                    if (k < 0) k = 0; // Calculate distance
                    if (k > b[i]) b[i] = k; // Update if the new distance is smaller
                }
            }
        }

        // Calculate the final answer based on the minimum distances
        ans = 0;
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
// <END-OF-CODE>
