
import java.util.Scanner;

public class s197768810{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read two integers n and m from the input
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Initialize a slice to hold m integers
        int[] a = new int[m];
        int sum = 0;

        // Read m integers into the slice a and calculate their sum
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
            sum += a[i];
        }

        // Check if the sum of integers exceeds n
        if (sum > n) {
            // Print -1 if the sum exceeds n and exit
            System.out.println(-1);
            return;
        }

        // Print the difference between n and the sum if it's within bounds
        System.out.println(n - sum);
    }
}
