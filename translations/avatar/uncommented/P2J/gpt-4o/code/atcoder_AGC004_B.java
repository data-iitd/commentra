import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        int[][] b = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            int m = a[i];
            for (int j = 0; j < n; j++) {
                int k = i - j;
                if (k < 0) {
                    k += n;
                }
                m = Math.min(m, a[k]);
                b[j][i] = m;
            }
        }
        
        long minSum = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            long currentSum = 0;
            for (int j = 0; j < n; j++) {
                currentSum += b[i][j];
            }
            minSum = Math.min(minSum, currentSum + x * i);
        }
        
        System.out.println(minSum);
        scanner.close();
    }
}

// <END-OF-CODE>
