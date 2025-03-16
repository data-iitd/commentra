
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

        // Separating positive and negative numbers
        for (int i = 0; i < N; i++) {
            if (lst[i] == 0) {
                K--;
            }
            if (lst[i] > 0) {
                lst_p.add(lst[i]);
            } else if (lst[i] < 0) {
                lst_m.add(lst[i]);
            }
        }

        // Initialization of pointers and variables
        int p = 0;
        int m = 0;
        int x = 0;
        int y = lst_m.size() - 1;
        int lastx = lst_p.size();
        int lasty = lst_m.size();

        // Function to check the minimum possible value
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
                ans = Math.min(ans, 2 * p + Math.abs(m), p + 2 * Math.abs(m));
            }
            return ans;
        }

        // Output the result of the check function with K as the argument
        System.out.println(check(K));
    }
}
