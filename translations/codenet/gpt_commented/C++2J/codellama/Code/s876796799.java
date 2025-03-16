import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Solution {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long[] a = new long[N];
    int[] ind_a = new int[N];
    for (int i = 0; i < N; i++) {
      a[i] = sc.nextLong();
    }
    for (int i = 0; i < N; i++) {
      ind_a[a[i] - 1] = i;
    }
    Set<Integer> used_inds = new TreeSet<>();
    long ans = 0;
    for (int i = 0; i < N; i++) {
      int cur_ind = ind_a[i];
      int left_border = -1;
      int right_border = N;
      if (!used_inds.isEmpty()) {
        left_border = used_inds.lower(cur_ind);
        right_border = used_inds.higher(cur_ind + 1);
      }
      ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1);
      used_inds.add(cur_ind);
    }
    System.out.println(ans);
  }
}

