import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input for two variables `n` and `d`
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        int[] x = new int[n];
        long m = 0; // Using long to avoid overflow
        long q = 0; // Using long to avoid overflow
        
        // Taking input for the list `x`
        for (int i = 0; i < n; i++) {
            x[i] = scanner.nextInt();
        }
        
        // Processing the list
        for (int a = 0; a < n - 1; a++) {
            if (x[a] >= x[a + 1]) {
                q = (x[a] - x[a + 1]) / d + 1;
                m += q;
                x[a + 1] += q * d;
            }
        }
        
        // Printing the value of `m`
        System.out.println(m);
        
        scanner.close();
    }
}
// <END-OF-CODE>
