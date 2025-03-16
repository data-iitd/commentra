
import java.util.Scanner;

public class s513492399{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
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

