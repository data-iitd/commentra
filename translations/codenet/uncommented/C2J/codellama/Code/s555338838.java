
public class InsertionSort {
  public static void main(String[] args) {
    int key, i, j, len, a[] = new int[101];
    Scanner sc = new Scanner(System.in);
    len = sc.nextInt();
    for (i = 0; i < len; i++) {
      a[i] = sc.nextInt();
    }

    for (j = 1; j < len; j++) {
      key = a[j];
      for (i = j - 1; i >= 0 && a[i] > key; i--) {
        a[i + 1] = a[i];
      }
      a[i + 1] = key;
    }

    for (i = 0; i < len; i++) {
      System.out.print(i != 0 ? " " : "");
      System.out.print(a[i]);
    }
    System.out.println();
  }
}

