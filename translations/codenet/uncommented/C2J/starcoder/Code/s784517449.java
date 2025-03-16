import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] A = new int[n];
    for(int i=0; i<n; i++) {
      A[i] = sc.nextInt();
    }
    int q = sc.nextInt();
    int sum = 0;
    for(int i=0;i<q;i++) {
      int k = sc.nextInt();
      if(binarySearch(A, k))
        sum++;
    }
    System.out.println(sum);
  }

  /* 二分探索 */
  public static boolean binarySearch(int[] A, int key) {
    int left = 0;
    int right = A.length;
    int mid;
    while(left < right) {
      mid = (left + right) / 2;
      if(key == A[mid]) return true; /* keyを発見 */
      if(key > A[mid]) left = mid + 1; /* 後半を探索 */
      else if(key < A[mid]) right = mid; /* 前半を探索 */
    }
    return false;
  }
}
