import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long[] a = new long[N];
        int[] ind_a = new int[N];

        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextLong();
        }

        for (int i = 0; i < N; i++) {
            ind_a[a[i] - 1] = i;
        }

        Set<Integer> used_inds = new HashSet<>();
        long ans = 0;

        for (int i = 0; i < N; i++) {
            long left_border = -1;
            long right_border = N;
            int cur_ind = ind_a[i];

            Integer left_it = null;
            Integer right_it = null;

            for (Integer index : used_inds) {
                if (index >= cur_ind) {
                    right_it = index;
                    break;
                }
                left_it = index;
            }

            if (left_it != null) {
                left_border = left_it;
            }
            if (right_it != null) {
                right_border = right_it;
            }

            ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long)i + 1);

            used_inds.add(cur_ind);
        }

        System.out.println(ans);
    }
}
