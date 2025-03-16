import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] A = new int[n];
    for (int i = 0; i < n; i++) {
      A[i] = sc.nextInt();
    }
    int q = sc.nextInt();
    int sum = 0;
    for (int i = 0; i < q; i++) {
      int k = sc.nextInt();
      if (binarySearch(A, 0, n - 1, k)) {
        sum++;
      }
    }
    System.out.println(sum);
  }

  public static boolean binarySearch(int[] A, int left, int right, int key) {
    if (left > right) {
      return false;
    }
    int mid = (left + right) / 2;
    if (key == A[mid]) {
      return true;
    }
    if (key > A[mid]) {
      return binarySearch(A, mid + 1, right, key);
    } else {
      return binarySearch(A, left, mid - 1, key);
    }
  }
}
