import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] A = new int[2 * n];
        
        for (int i = 0; i < 2 * n; i++) {
            A[i] = scanner.nextInt();
        }
        
        Arrays.sort(A);
        long ans = 0;
        
        for (int i = 2 * n - 1; i >= n; i -= 2) {
            ans += A[i];
        }
        
        System.out.println(ans);
        scanner.close();
    }
}
// <END-OF-CODE>
