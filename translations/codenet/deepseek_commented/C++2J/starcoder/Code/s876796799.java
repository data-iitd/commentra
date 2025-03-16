import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();
    long[] a = new long[N];
    int[] ind_a = new int[N];
    for(int i = 0; i < N; i++){
      a[i] = in.nextLong();
    }
    for(int i = 0; i < N; i++){
      ind_a[a[i] - 1] = i;
    }

    Set<Integer> used_inds = new HashSet<Integer>();
    long ans = 0;
    for(int i = 0; i < N; i++){
      long left_border;
      long right_border;
      long cur_ind = ind_a[i];
      Iterator<Integer> left_it = used_inds.lowerBound(cur_ind);
      Iterator<Integer> right_it = used_inds.lowerBound(cur_ind + 1);

      if(left_it.equals(used_inds.iterator())){
        left_border = -1;
      } else {
        if(left_it.equals(used_inds.end()) ||!left_it.next().equals(cur_ind)){
          left_it.previous();
        }
        left_border = left_it.next();
      }
      if(right_it.equals(used_inds.end())){
        right_border = N;
      } else {
        right_border = right_it.next();
      }
      ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long)i + 1);

      // Debugging output (commented out)
      //System.out.println(i + " " + left_border + " " + right_border);
      //System.out.println(ans);

      used_inds.add(cur_ind);
    }

    System.out.println(ans);
  }
}

