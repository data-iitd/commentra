import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking two integer inputs, `n` and `m`
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        int i = 1; // Initializing `i` to 1
        
        while (m >= i) { // The loop continues as long as `m` is greater than or equal to `i`
            m -= i; // Subtracting `i` from `m`
            i = (i % n) + 1; // Updating `i` to be `(i % n) + 1`
        }
        
        System.out.println(m); // Printing the value of `m` after the loop completes
        
        scanner.close();
    }
}
// <END-OF-CODE>
