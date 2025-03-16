import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static class Arm {
        int l, r;

        Arm(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Arm[] arms = new Arm[n];

        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int l = scanner.nextInt();
            arms[i] = new Arm(x - l, x + l);
        }

        Arrays.sort(arms, Comparator.comparingInt(a -> a.r));

        int ans = 1;
        int r = arms[0].r;
        for (int i = 1; i < n; i++) {
            if (arms[i].l >= r) {
                ans++;
                r = arms[i].r;
            }
        }
        System.out.println(ans);
    }
}
//<END-OF-CODE>
