import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read values of n, m, s, and f
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int s = scanner.nextInt();
        int f = scanner.nextInt();
        
        // Determine the direction and character based on the starting and finishing points
        int d;
        char c;
        if (s < f) {
            d = 1;  // Set direction to right (R)
            c = 'R';
        } else {
            d = -1; // Set direction to left (L)
            c = 'L';
        }
        
        StringBuilder res = new StringBuilder(); // Initialize a StringBuilder to store the result
        int i = 1; // Initialize step counter
        int j = s; // Initialize current position
        int t, l, r; // Variables for time step and range
        t = scanner.nextInt();
        l = scanner.nextInt();
        r = scanner.nextInt();
        int k = 1; // Initialize the current time step
        
        // Loop until the current position reaches the finishing point
        while (j != f) {
            if (i > t && k < m) { // Check if it's time to update the time step and there are more steps
                t = scanner.nextInt(); // Read new values for t
                l = scanner.nextInt(); // Read new values for l
                r = scanner.nextInt(); // Read new values for r
                k++; // Increment the time step counter
            }
            
            if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) { // Check if it's the specified time step and the position is within the allowed range
                res.append('X'); // Append 'X' to the result string
            } else {
                res.append(c); // Append the direction character to the result string
                j += d; // Update the current position
            }
            i++; // Increment the step counter
        }
        
        System.out.println(res.toString()); // Print the result string
        scanner.close();
    }
}
// <END-OF-CODE>
