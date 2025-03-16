import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of n and m from standard input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize a list `b` with 1s, size is 2*n
        int[] b = new int[n * 2];
        for (int i = 0; i < b.length; i++) {
            b[i] = 1;
        }
        
        // Set specific positions in `b` to 0
        b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;
        
        for (int i = 0; i < m; i++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            // Update `b` based on the input pairs
            b[r - 1] = b[n + c - 1] = 0;
        }
        
        // Check if `n` is odd and specific positions in `b` are 1, then set them to 0
        if (n % 2 == 1 && b[n / 2] == 1 && b[n + n / 2] == 1) {
            b[n / 2] = 0;
        }
        
        // Print the sum of the list `b`
        int sum = 0;
        for (int value : b) {
            sum += value;
        }
        System.out.println(sum);
        
        scanner.close();
    }
}
// <END-OF-CODE>
