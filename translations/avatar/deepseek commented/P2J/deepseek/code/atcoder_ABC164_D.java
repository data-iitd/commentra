import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        int l = 2019;
        int[] m = new int[l];
        m[0] = 1;
        int a = 0;
        int r = 0;
        for (int i = 0; i < s.length(); i++) {
            int e = s.charAt(s.length() - 1 - i);
            a += (e - '0') * powMod(10, i, l);
            a %= l;
            r += m[a];
            m[a]++;
        }
        System.out.println(r);
    }

    private static int powMod(int base, int exp, int mod) {
        int result = 1;
        base %= mod;
        while (exp > 0) {
            if ((exp & 1) == 1) { // if exp is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1; // divide exp by 2
        }
        return result;
    }
}

