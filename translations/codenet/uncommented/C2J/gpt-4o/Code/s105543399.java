import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n, a, m, M, c = 0;
        m = 100000000;
        M = -100000000;
        
        n = scanner.nextLong();

        for (long i = 1; i <= n; i++) {
            a = scanner.nextLong();
            if (a > M) {
                M = a;
            }
            if (a < m) {
                m = a;
            }
            c += a;
        }
        
        System.out.printf("%d %d %d\n", m, M, c);
        scanner.close();
    }
}

// <END-OF-CODE>
