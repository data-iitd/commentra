import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[] a = new int[10000];
        int min, max, n;
        long sum = 0;
        
        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            sum += a[i];
        }
        
        max = min = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > max) max = a[i];
            if (a[i] < min) min = a[i];
        }
        
        System.out.printf("%d %d %d%n", min, max, sum);
        
        scanner.close();
    }
}

// <END-OF-CODE>
