import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int N = 200010;
    static long[] a = new long[N];
    static long[] q = new long[N];
    static long tot;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextLong();
        }
        
        Arrays.sort(a, 1, (int) n + 1);
        
        for (int i = 1; i <= n; i++) {
            if (i < n && a[i] == a[i + 1]) {
                q[++tot] = a[i];
                i++;
            }
        }
        
        System.out.println(q[(int) tot] * q[(int) (tot - 1)]);
        scanner.close();
    }
}

// <END-OF-CODE>
