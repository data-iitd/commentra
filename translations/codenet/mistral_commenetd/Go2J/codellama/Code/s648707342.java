
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Arm[] as = new Arm[n];

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int l = sc.nextInt();

            as[i] = new Arm(x - l, x + l);
        }

        sort(as);

        int ans = 1;
        int r = as[0].r;

        for (int i = 1; i < n; i++) {
            if (as[i].l >= r) {
                ans++;
                r = as[i].r;
            }
        }

        System.out.println(ans);
    }

    public static void sort(Arm[] as) {
        for (int i = 0; i < as.length - 1; i++) {
            for (int j = i + 1; j < as.length; j++) {
                if (as[i].r > as[j].r) {
                    Arm temp = as[i];
                    as[i] = as[j];
                    as[j] = temp;
                }
            }
        }
    }

    public static class Arm {
        int l;
        int r;

        public Arm(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }
}

