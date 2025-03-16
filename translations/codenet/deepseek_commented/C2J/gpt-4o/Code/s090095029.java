import java.util.Scanner;  // Import Scanner for input
import java.util.Arrays;   // Import Arrays for array manipulation

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object for input
        int n = scanner.nextInt();  // Read integer n
        int m = scanner.nextInt();  // Read integer m
        
        boolean[] r0 = new boolean[n];  // Initialize boolean array r0
        Arrays.fill(r0, false);  // Fill r0 with false values
        int[] r1 = new int[n];  // Initialize integer array r1
        int nr1 = 0;  // Initialize counter for r1
        
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();  // Read integer a
            int b = scanner.nextInt();  // Read integer b
            
            if (a > b) {  // Ensure a is less than or equal to b
                int t = a;
                a = b;
                b = t;
            }
            if (a == 1) r0[b - 1] = true;  // If a is 1, set r0[b-1] to true
            if (b == n) r1[nr1++] = a - 1;  // If b is n, add a-1 to r1
        }
        
        boolean res = false;  // Initialize result as false
        for (int i = 0; i < nr1; i++) {
            if (r0[r1[i]]) res = true;  // Check if any element in r1 has a true in r0
        }
        
        System.out.println(res ? "POSSIBLE" : "IMPOSSIBLE");  // Print result
        scanner.close();  // Close the scanner
    }
}
// <END-OF-CODE>
