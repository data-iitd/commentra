import java.util.*;

public class BinarySearch {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    int[] A = new int[n];
    for(int i=0; i<n; i++) {
      A[i] = in.nextInt();
    }
    int q = in.nextInt();
    int sum = 0;
    for(int i=0;i<q;i++) {
      int k = in.nextInt();
      if(binarySearch(A, k))
        sum++;
    }
    System.out.println(sum);
  }

  /* 
   * binarySearch function performs a binary search on the array A to find a given key.
   * It returns 1 if the key is found, otherwise it returns 0.
   */
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
