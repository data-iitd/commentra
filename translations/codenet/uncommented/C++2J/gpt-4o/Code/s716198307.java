import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        double avg = 0, s, ans = 0;
        
        n = scanner.nextInt();
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            avg += a[i];
        }
        
        avg /= n;
        s = Math.abs(a[0] - avg);
        
        for (int i = 1; i < n; i++) {
            if (s > Math.abs(a[i] - avg)) {
                s = Math.abs(a[i] - avg);
                ans = i;
            }
        }
        
        System.out.println((int) ans);
        scanner.close();
    }
}

// <END-OF-CODE>
