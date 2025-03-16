import java.util.Scanner;

public class Main {
    
    // Function to calculate the greatest common divisor (GCD)
    public static long gcd(long a, long b) {
        long c;
        while (b > 0) {
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

    // Function to calculate (a^n) % mod using modular exponentiation
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

    // Function to calculate modular multiplicative inverse
    public static long modinv(long a, long mod) {
        return modpow(a, mod - 2, mod);
    }

    // Function to find the maximum of two integers
    public static int max(int a, int b) {
        return a < b ? b : a;
    }

    // Function to find the minimum of two integers
    public static int min(int a, int b) {
        return a < b ? a : b;
    }

    // Function to update a variable if it is smaller
    public static void chmax(int[] a, int b) {
        if (a[0] < b) {
            a[0] = b;
        }
    }

    // Function to update a variable if it is larger
    public static void chmin(int[] a, int b) {
        if (a[0] > b) {
            a[0] = b;
        }
    }

    // Main function
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
