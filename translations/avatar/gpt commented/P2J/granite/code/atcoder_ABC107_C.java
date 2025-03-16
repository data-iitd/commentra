
import java.util.*;

public class atcoder_ABC107_C{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] lst = new int[N];
        for (int i = 0; i < N; i++) {
            lst[i] = sc.nextInt();
        }
        List<Integer> lst_p = new ArrayList<>();
        List<Integer> lst_m = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (lst[i] == 0) {
                K--;
            }
            if (lst[i] > 0) {
                lst_p.add(lst[i]);
            }
            if (lst[i] < 0) {
                lst_m.add(lst[i]);
            }
        }
        int p = 0;
        int m = 0;
        int x = lst_p.size();
        int y = lst_m.size() - 1;
        int lastx = lst_p.size();
        int lasty = lst_m.size();
        int ans = 100000000;
        for (int j = 0; j <= K; j++) {
            if (j > lastx || K - j > lasty) {
                continue;
            }
            if (j == 0) {
                p = 0;
            } else {
                p = lst_p.get(j - 1);
            }
            if (K - j == 0) {
                m = 0;
            } else {
                m = lst_m.get(lasty - (K - j));
            }
            ans = Math.min(ans, 2 * p + Math.abs(m), p + 2 * Math.abs(m));
        }
        System.out.println(ans);
    }
}
