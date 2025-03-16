
// +build ignore

import java.io.*;
import java.util.*;

public class s731620136{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String S = sc.next();

    if (N == 0) {
    }

    if (N < 4) {
      System.out.println(0);
      return;
    }

    int nr = 0;
    int nb = 0;
    int ng = 0;
    for (int i = 0; i < N; i++) {
      if (S.charAt(i) == 'R') {
        nr++;
      } else if (S.charAt(i) == 'B') {
        nb++;
      } else {
        ng++;
      }
    }

    int same = 0;
    int etot = 0;
    for (int a = 1; a < N; a++) {
      int i = 0;
      int j = a;
      int k = 2 * a;
      if (k >= N) {
        break;
      }
      while (k < N) {
        etot++;
        // System.out.printf("(%4d) [%2d] (%3d, %3d, %3d)", etot, a, i, j, k);
        if (S.charAt(i)!= S.charAt(j) && S.charAt(i)!= S.charAt(k) && S.charAt(j)!= S.charAt(k)) {
          same++;
          // System.out.printf(" (%4d)", same);
        }
        // System.out.println();
        i++;
        j++;
        k++;
      }
    }

    int tot = nr * nb * ng;

    // int sum = 0;
    // int sum2 = 0;
    // for (int k = 2; k < N; k++) {
    //   for (int j = 1; j < k; j++) {
    //     for (int i = 0; i < j; i++) {
    //       if (j - i == k - j) {
    //         if (S.charAt(i)!= S.charAt(j) && S.charAt(i)!= S.charAt(k) && S.charAt(j)!= S.charAt(k)) {
    //           sum2++;
    //         }
    //         continue;
    //       }

    //       if (S.charAt(i)!= S.charAt(j) && S.charAt(i)!= S.charAt(k) && S.charAt(j)!= S.charAt(k)) {
    //         sum++;
    //       }
    //     }
    //   }
    // }

    // System.out.println(tot, same, sum, sum2);
    System.out.println(tot - same);
  }
}

// END-OF-CODE