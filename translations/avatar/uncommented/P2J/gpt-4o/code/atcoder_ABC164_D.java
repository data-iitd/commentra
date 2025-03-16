import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int l = 2019;
        int[] m = new int[l + 1];
        long a = 0;
        long r = 0;

        m[0] = 1; // Initialize m[0] to 1

        for (int i = 0; i < s.length(); i++) {
            char e = s.charAt(s.length() - 1 - i);
            a += (e - '0') * pow(10, i, l);
            r += m[(int)(a % l)];
            m[(int)(a % l)]++;
        }

        System.out.println(r);
    }

    // Function to calculate (base^exp) % mod
    private static long pow(int base, int exp, int mod) {
        long result = 1;
        long b = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }
        return result;
    }
}

// <END-OF-CODE>
