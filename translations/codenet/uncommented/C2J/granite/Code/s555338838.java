
import java.util.Scanner;

public class s555338838{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int len = scanner.nextInt();
    int[] a = new int[len];
    for (int i = 0; i < len; i++) {
      a[i] = scanner.nextInt();
    }

    for (int j = 1; j < len; j++) {
      for (int i = 0; i < len; i++) {
        System.out.print(i!= 0? " " + a[i] : a[i]);
      }
      System.out.println();
      int key = a[j];
      for (int i = j - 1; i >= 0 && a[i] > key; i--) {
        a[i + 1] = a[i];
      }
      a[i + 1] = key;
    }

    for (int i = 0; i < len; i++) {
      System.out.print(i!= 0? " " + a[i] : a[i]);
    }
    System.out.println();
  }
}
// 