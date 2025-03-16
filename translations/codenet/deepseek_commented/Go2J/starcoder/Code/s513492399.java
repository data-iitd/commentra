import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        int ans = 0;

        for (int a = 1; a <= k; a++) {
            for (int b = 1; b <= k; b++) {
                for (int c = 1; c <= k; c++) {
                    ans += gcd(a, gcd(b, c));
                }
            }
        }

        System.out.println(ans);
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

