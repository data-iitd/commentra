
import java.util.Scanner;
import java.util.Arrays;

class s787964396 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] a = new int[n+1];
    int[] b = new int[n+1];
    for (int i = 0; i < n; i++) {
      a[i+1] = sc.nextInt();
    }
    CountingSort(a, b, n);
    System.out.print(b[1]);
    for (int i = 2; i < n+1; i++) {
      System.out.print(" " + b[i]);
    }
    System.out.println();
  }
  public static void CountingSort(int[] a, int[] b, int k) {
    int[] c = new int[10000];
    for (int i = 0; i <= 10000; i++) {
      c[i] = 0;
    }
    for (int j = 0; j < k; j++) {
      c[a[j+1]]++;
    }
    for (int i = 1; i <= 10000; i++) {
      c[i] += c[i-1];
    }
    for (int j = k; 0 < j; j--) {
      b[c[a[j]]] = a[j];
      c[a[j]]--;
    }
  }
}
