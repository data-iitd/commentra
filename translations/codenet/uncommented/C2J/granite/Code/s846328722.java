
import java.util.Scanner;

class s846328722 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int i, n, s[] = new int[100000], q, t, count = 0;

    n = sc.nextInt();

    for (i = 0; i < n; i++) {
      s[i] = sc.nextInt();
    }

    q = sc.nextInt();

    for (i = 0; i < q; i++) {
      t = sc.nextInt();
      if (linersearch(s, n, t)) count++;
    }
    System.out.println(count);
  }

  public static boolean linersearch(int[] a, int n, int key) {
    int i = 0;

    a[n] = key;

    while (a[i]!= key) {
      i++;
    }
    return i!= n;
  }
}
