import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        int t = 0;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 1; j < n; j++) {
                if (j <= i) {
                    continue;
                }
                int m = a[i] * a[j];
                s = s + m;
            }
            t = t + s;
        }
        
        System.out.println(t);
        scanner.close();
    }
}

// <END-OF-CODE>
