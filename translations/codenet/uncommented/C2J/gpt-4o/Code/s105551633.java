import java.util.Scanner;

public class Main {
    private static long digit(long n) {
        long res = 0;
        while (n > 0) {
            res++;
            n /= 10;
        }
        return res;
    }

    private static void run() {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long min = digit(n);
        for (long i = 1; i * i <= n; i++) {
            if (n % i != 0) continue;
            long a = i;
            long b = n / i;
            min = Math.min(min, Math.max(digit(a), digit(b)));
        }
        System.out.println(min);
    }

    public static void main(String[] args) {
        run();
    }
}

// <END-OF-CODE>
