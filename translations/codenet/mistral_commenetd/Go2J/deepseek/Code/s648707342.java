import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        List<Arm> arms = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int l = scanner.nextInt();
            arms.add(new Arm(x - l, x + l));
        }

        Collections.sort(arms, (a, b) -> Integer.compare(a.r, b.r));

        int ans = 1;
        int r = arms.get(0).r;

        for (int i = 1; i < n; i++) {
            if (arms.get(i).l >= r) {
                ans++;
                r = arms.get(i).r;
            }
        }

        System.out.println(ans);
        scanner.close();
    }

    static class Arm {
        int l, r;

        Arm(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }
}
