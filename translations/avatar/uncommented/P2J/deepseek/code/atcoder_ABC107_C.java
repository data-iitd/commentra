import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        List<Integer> lst = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            lst.add(scanner.nextInt());
        }

        List<Integer> lst_p = new ArrayList<>();
        List<Integer> lst_m = new ArrayList<>();
        for (int num : lst) {
            if (num == 0) {
                K--;
            } else if (num > 0) {
                lst_p.add(num);
            } else {
                lst_m.add(num);
            }
        }

        int p = 0;
        int m = 0;
        int lastx = lst_p.size();
        int lasty = lst_m.size();

        int check(int k) {
            int ans = Integer.MAX_VALUE;
            for (int j = 0; j <= k; j++) {
                if (j > lastx || k - j > lasty) {
                    continue;
                }
                if (j == 0) {
                    p = 0;
                } else {
                    p = lst_p.get(j - 1);
                }
                if (k - j == 0) {
                    m = 0;
                } else {
                    m = lst_m.get(lasty - (k - j));
                }
                ans = Math.min(ans, Math.min(2 * p + Math.abs(m), p + 2 * Math.abs(m)));
            }
            return ans;
        }

        System.out.println(check(K));
    }
}
