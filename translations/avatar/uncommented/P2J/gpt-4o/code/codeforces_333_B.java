import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and m
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize the array b
        int[] b = new int[n * 2];
        for (int i = 0; i < b.length; i++) {
            b[i] = 1;
        }
        b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;
        
        // Read m pairs of r and c
        for (int i = 0; i < m; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            b[r - 1] = 0;
            b[n + c - 1] = 0;
        }
        
        // Check the condition for n being odd
        if (n % 2 == 1 && b[n / 2] == 1 && b[n + n / 2] == 1) {
            b[n / 2] = 0;
        }
        
        // Calculate the sum of the array b
        int sum = 0;
        for (int value : b) {
            sum += value;
        }
        
        // Print the result
        System.out.println(sum);
        
        scanner.close();
    }
}
// <END-OF-CODE>
