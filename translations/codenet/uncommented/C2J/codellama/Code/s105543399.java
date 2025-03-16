
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long a, m, M, c, b, i;
        c = 0;
        m = 100000000;
        M = -100000000;

        for (i = 1; i <= n; i++) {
            a = sc.nextLong();
            if (a > M) {
                M = a;
            }
            if (a < m) {
                m = a;
            }
            c = c + a;
        }
        System.out.println(m + " " + M + " " + c);
    }
}

