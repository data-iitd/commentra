import java.util.Scanner;

public class Main {
    
    public static long gcd(long a, long b) {
        long c;
        while (b > 0) {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

    public static long modpow(long a, long n, long mod) {
        long ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            n /= 2;
        }
        return ans;
    }

    public static long modinv(long a, long mod) {
        return modpow(a, mod - 2, mod);
    }

    public static int max(int a, int b) {
        return a < b ? b : a;
    }

    public static int min(int a, int b) {
        return a < b ? a : b;
    }

    public static void chmax(int[] a, int b) {
        if (a[0] < b) {
            a[0] = b;
        }
    }

    public static void chmin(int[] a, int b) {
        if (a[0] > b) {
            a[0] = b;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int sum = 0;
        int m = n;

        for (int i = 0; i < 9; i++) {
            sum += n % 10;
            n /= 10;
        }

        if (m % sum == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }

        scanner.close();
    }
}

// <END-OF-CODE>
