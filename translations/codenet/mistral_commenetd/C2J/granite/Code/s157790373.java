

import java.util.*;

class s157790373 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] A = new int[n];
    for (int i = 0; i < n; i++) {
      A[i] = sc.nextInt();
    }
    int q = sc.nextInt();
    for (int i = 0; i < q; i++) {
      int m = sc.nextInt();
      boolean flag = solve(A, 0, m);
      if (flag) {
        System.out.println("yes");
      } else {
        System.out.println("no");
      }
    }
  }

  public static boolean solve(int[] A, int i, int m) {
    if (i > A.length) {
      return false;
    }
    if (m < 0) {
      return false;
    }
    if (m == 0 || m - A[i + 1] == 0) {
      return true;
    }
    return solve(A, i + 1, m) || solve(A, i + 1, m - A[i]);
  }
}

