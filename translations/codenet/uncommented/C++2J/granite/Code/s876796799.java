
import java.util.*;

public class s876796799{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] a = new long[N];
    int[] ind_a = new int[N];
    for (int i = 0; i < N; i++) {
      a[i] = sc.nextLong();
    }
    for (int i = 0; i < N; i++) {
      ind_a[(int)a[i] - 1] = i;
    }

    TreeSet<Integer> used_inds = new TreeSet<>();
    long ans = 0;
    for (int i = 0; i < N; i++) {
      long left_border;
      long right_border;
      long cur_ind = ind_a[i];
      Integer left_it = used_inds.lower(cur_ind);
      Integer right_it = used_inds.higher(cur_ind);

      if (left_it == null) {
        left_border = -1;
      } else {
        left_border = left_it;
      }
      if (right_it == null) {
        right_border = N;
      } else {
        right_border = right_it;
      }
      ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long)i + 1);

      // System.out.println(i + " " + left_border + " " + right_border);
      // System.out.println(ans);

      used_inds.add(cur_ind);
    }

    System.out.println(ans);
  }
}
