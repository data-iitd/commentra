import java.util.Scanner;

public class GrowthCounter {
    public static void main(String[] args) {
        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from input: t (target), s (initial value), and q (growth factor)
        int t = scanner.nextInt();
        int s = scanner.nextInt();
        int q = scanner.nextInt();
        
        // Initialize a counter for the number of iterations
        int ans = 0;

        // Loop until the initial value s is less than the target t
        while (s < t) {
            // Multiply the current value of s by the growth factor q
            s *= q;
            // Increment the counter for each multiplication
            ans++;
        }

        // Print the total number of multiplications needed for s to reach or exceed t
        System.out.println(ans);
        
        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
