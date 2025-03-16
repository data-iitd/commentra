import java.util.Scanner;

public class Main {
    // Define custom data types
    static long INF = (1L << 60);
    static long MOD1 = 1000000007;
    static long MOD2 = 998244353;

    // Function to read an integer from the standard input
    static long cin(Scanner scanner) {
        return scanner.nextLong();
    }

    public static void main(String[] args) {
        // Main function
        Scanner scanner = new Scanner(System.in);

        long l, r, d;
        long ans = 0;

        l = cin(scanner);
        r = cin(scanner);
        d = cin(scanner);

        for (long i = l; i <= r; i++) {
            if (i % d == 0) ans++;
        }

        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
