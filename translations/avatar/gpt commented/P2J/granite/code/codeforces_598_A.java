
import java.util.Scanner;

public class codeforces_598_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int s = (1 + n) * n / 2;
            int t2 = 1;
            while (t2 <= n) {
                s -= 2 * t2;
                t2 *= 2;
            }
            System.out.println(s);
        }
    }
}
