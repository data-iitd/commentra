
import java.util.*;

class s497500962 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt(); // Number of red items
        int G = sc.nextInt(); // Number of green items
        int B = sc.nextInt(); // Number of blue items
        int N = sc.nextInt(); // Total number of items to choose

        int ans = 0; // Variable to store the count of valid combinations

        // Iterate over possible counts of red items (x)
        for (int x = 0; x <= N; x++) {
            // Iterate over possible counts of green items (y)
            for (int y = 0; y <= N; y++) {
                // Calculate the remaining items after choosing x red and y green
                int tmp = N - R * x - G * y;
                // Check if the remaining items can be fully represented by blue items
                if (tmp >= 0 && tmp % B == 0) {
                    ans++; // Increment the count of valid combinations
                }
            }
        }

        // Output the total count of valid combinations
        System.out.println(ans);
    }
}

// Input. ----------

// Function to read the next integer from input
int nextInt() {
    return Integer.parseInt(sc.next()); // Convert the next token to an integer
}

// Function to read the next float from input
float nextFloat() {
    return Float.parseFloat(sc.next()); // Convert the next token to a float
}

// Function to read the next string from input
String nextString() {
    return sc.next(); // Return the next token as a string
}

// ---------- Input.

// Util. ----------

// Function to compute the absolute value of an integer
int abs(int x) {
    return Math.abs(x); // Return the absolute value
}

// Function to compute the minimum of two integers
int min(int x, int y) {
    return Math.min(x, y); // Return the minimum value
}

// Function to compute the maximum of two integers
int max(int x, int y) {
    return Math.max(x, y); // Return the maximum value
}

// ---------- Util.

// END-OF-CODE