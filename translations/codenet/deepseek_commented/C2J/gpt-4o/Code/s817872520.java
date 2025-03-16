import java.util.Scanner;

public class EvacuationRoutes {
    static final int INF = 0x5fffffff; // Define the maximum possible integer value
    static int[] a = new int[100002]; // Declare array 'a' to store integers
    static int[] b = new int[100002]; // Declare array 'b' to store evacuation routes

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int w = scanner.nextInt(); // Read the width of the array and store it in 'w'
        scanner.nextLine(); // Consume the newline character
        
        int ans = 0, f = 0; // Initialize variables
        for (int i = 1; i <= w; i++) { // Start parsing the input
            a[i] = scanner.nextInt(); // Read the next integer and store it in 'a[i]'
            if (a[i] == 0) f |= 1; // Set flag if zero is found
            else if (a[i] < 0) f |= 2; // Set flag if negative number is found
            else ans += a[i]; // Add to the sum if positive number
        }
        
        if (ans == 0 || (f & 1) == 0) { // If no positive numbers or zero found, output 0
            System.out.println("0");
            return;
        }
        if ((f & 2) == 0) { // If no negative numbers, output the sum of positive numbers
            System.out.println(ans);
            return;
        }

        // Calculate the minimum evacuation routes
        int close = 0;
        f = 0;
        for (int i = 1; i <= w; i++) { // First pass from left to right
            if (a[i] == 0) {
                close = INF;
                f = -1; // Reset if zero is found
            } else if (a[i] < 0) {
                if (f < 0 || close - (i - f) > -a[i]) {
                    close = -a[i];
                    f = i; // Update the closest negative number
                }
            } else {
                if (f < 0) b[i] = INF; // If no negative number found yet, set to INF
                else {
                    int k = close - (i - f);
                    if (k < 0) k = 0; // Calculate the evacuation route
                    b[i] = k;
                }
            }
        }

        close = 0;
        f = w;
        for (int i = w; i >= 1; i--) { // Second pass from right to left
            if (a[i] == 0) {
                close = INF;
                f = -1; // Reset if zero is found
            } else if (a[i] < 0) {
                if (f < 0 || close - (f - i) > -a[i]) {
                    close = -a[i];
                    f = i; // Update the closest negative number
                }
            } else {
                if (f < 0) b[i] = INF; // If no negative number found yet, set to INF
                else {
                    int k = close - (f - i);
                    if (k < 0) k = 0; // Calculate the evacuation route
                    if (k > b[i]) b[i] = k; // Update if a better route is found
                }
            }
        }

        ans = 0;
        for (int i = 1; i <= w; i++) { // Calculate the total evacuation route
            if (a[i] > 0) {
                if (b[i] > a[i]) ans += a[i]; // Add the minimum of b[i] and a[i]
                else ans += b[i];
            }
        }
        System.out.println(ans); // Output the final result
        scanner.close();
    }
}
// <END-OF-CODE>
