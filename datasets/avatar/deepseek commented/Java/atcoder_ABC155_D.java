import java.util.*; // Import necessary libraries for input and mathematical operations.
import java.math.*; // Import for BigInteger class if needed.

public class Main {
    static int mod = (int) 1e9 + 7; // Define constant for modulo operation.
    static int DX[] = { -1, 0, 1, 0 }, DY[] = { 0, -1, 0, 1 }; // Define directions for movement.
    
    static int n; // Declare variable for the size of the array.
    static long k; // Declare variable for the target value.
    static long a[]; // Declare array to store the values.
    
    public static void main(String[] args) {
        Scanner fs = new Scanner(System.in); // Create a Scanner object for input.
        n = fs.nextInt(); // Read the size of the array.
        k = fs.nextLong(); // Read the target value.
        a = new long[n]; // Initialize the array.
        
        for (int i = 0; i < n; ++i) {
            a[i] = fs.nextLong(); // Read the elements of the array.
        }
        
        Arrays.sort(a); // Sort the array.
        
        long INF = (long) (1e18) + 1; // Define a large number as infinity.
        long l = -INF; // Initialize the left boundary of the search.
        long r = INF; // Initialize the right boundary of the search.
        
        while (l + 1 < r) { // Perform binary search.
            long c = (l + r) / 2; // Calculate the middle point.
            if (check(c)) {
                l = c; // Adjust the left boundary.
            } else {
                r = c; // Adjust the right boundary.
            }
        }
        
        System.out.println(l); // Print the result.
    }
    
    static boolean check(long x) {
        long tot = 0; // Initialize the total count.
        
        for (int i = 0; i < n; i++) {
            long now = a[i]; // Get the current element.
            int l = 0, r = n; // Initialize the boundaries for binary search.
            
            if (now >= 0) { // If the current element is non-negative.
                while (l < r) { // Perform binary search.
                    int c = (l + r) / 2;
                    if (now * a[c] < x) {
                        l = c + 1; // Adjust the left boundary.
                    } else {
                        r = c; // Adjust the right boundary.
                    }
                }
                tot += l; // Add the result to the total.
            } else { // If the current element is negative.
                while (l < r) { // Perform binary search.
                    int c = (l + r) / 2;
                    if (now * a[c] >= x) {
                        l = c + 1; // Adjust the left boundary.
                    } else {
                        r = c; // Adjust the right boundary.
                    }
                }
                tot += (n - l); // Add the result to the total.
            }
            
            if ((long) a[i] * a[i] < x) {
                tot--; // Adjust the total if necessary.
            }
        }
        
        if (tot / 2 < k) {
            return true; // Return true if the count is less than k.
        } else {
            return false; // Return false otherwise.
        }
    }
}