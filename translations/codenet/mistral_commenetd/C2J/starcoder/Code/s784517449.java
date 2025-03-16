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
      if (binarySearch(A, k)) {
        sum++;
      }
    }
    System.out.println(sum);
  }

  public static boolean binarySearch(int[] A, int key) {
    int left = 0;
    int right = A.length - 1;
    int mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (key == A[mid]) {
        return true;
      }
      if (key > A[mid]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
}

