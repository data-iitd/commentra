
import java.util.Scanner;

public class atcoder_AGC006_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        char[] s = scanner.next().toCharArray();
        char[] t = scanner.next().toCharArray();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (s[i + j]!= t[j]) {
                    break;
                }
                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }
        System.out.println(2 * n - cnt);
    }
}
