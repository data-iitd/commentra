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
            int e = s.charAt(s.length() - 1 - i) - '0';
            a += e * powMod(10, i, l);
            r += m[a % l];
            m[a % l]++;
        }
        System.out.println(r);
    }

    private static int powMod(int base, int exp, int mod) {
        int result = 1;
        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) { // if exp is odd
                result = (result * base) % mod;
            }
            exp = exp >> 1; // divide exp by 2
            base = (base * base) % mod;
        }
        return result;
    }
}
