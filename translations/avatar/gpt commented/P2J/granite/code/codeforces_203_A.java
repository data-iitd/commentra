
import java.util.Scanner;

public class codeforces_203_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] xxs = scanner.nextLine().split(" ");
        int x = Integer.parseInt(xxs[0]);
        int t = Integer.parseInt(xxs[1]);
        int a = Integer.parseInt(xxs[2]);
        int b = Integer.parseInt(xxs[3]);
        int da = Integer.parseInt(xxs[4]);
        int db = Integer.parseInt(xxs[5]);

        if (x == 0) {
            System.out.println("YES");
            return;
        }

        for (int i = 0; i <= t - 1; i++) {
            for (int j = 0; j <= t - 1; j++) {
                if (a - da * i == x || b - db * j == x) {
                    System.out.println("YES");
                    return;
                }
                if ((a - da * i) + (b - db * j) == x) {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
    }
}
