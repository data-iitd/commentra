import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();
        
        int[] a = new int[106]; // Array size is 106 to accommodate 0 to n
        
        for (int i = 0; i < m; ++i) {
            int temp = scanner.nextInt();
            a[temp] = 1;
        }
        
        int ansl = 0, ansr = 0;
        
        for (int i = x; i <= n; ++i) {
            ansr += a[i];
        }
        
        for (int i = x; i >= 0; --i) {
            ansl += a[i];
        }
        
        System.out.println(Math.min(ansl, ansr));
        
        scanner.close();
    }
}

// <END-OF-CODE>
