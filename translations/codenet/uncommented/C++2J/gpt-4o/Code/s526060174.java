import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] x = new int[32]; // Array size is 32 to accommodate indices 1 to 31
        
        for (int i = 0; i < n; i++) {
            int k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                int a = scanner.nextInt();
                x[a]++;
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            if (x[i] == n) {
                ans++;
            }
        }
        
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
