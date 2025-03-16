import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    card[] a = new card[n];
    card[] b = new card[n];
    for (int i = 0; i < n; i++) {
      String s = sc.next();
      int v = sc.nextInt();
      a[i] = new card(s.charAt(0), v);
      b[i] = new card(s.charAt(0), v);
    }
    ms(a, n, 0, n);
    qs(b, n, 0, n - 1);
    boolean stable = true;
    for (int i = 0; i < n; i++) {
      if (a[i].s!= b[i].s) {
        stable = false;
      }
    }
    if (stable) {
      System.out.println("Stable");
    } else {
      System.out.println("Not stable");
    }
    for (int i = 0; i < n; i++) {
      System.out.println(b[i].s + " " + b[i].v);
    }
  }

  public static void ms(card[] a, int n, int l, int r) {
    int m;
    if (l + 1 < r) {
      m = (l + r) / 2;
      ms(a, n, l, m);
      ms(a, n, m, r);
      me(a, n, l, m, r);
    }
  }

  public static void me(card[] a, int n, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l;
    int n2 = r - m;
    card[] L = new card[n1 + 2];
    card[] R = new card[n2 + 2];
    for (i = 0; i < n1; i++) L[i] = a[l + i];
    for (i = 0; i < n2; i++) R[i] = a[m + i];
    L[n1] = new card(' ', 2000000000);
    R[n2] = new card(' ', 2000000000);
    i = 0;
    j = 0;
    for (k = l; k < r; k++) {
      if (L[i].v <= R[j].v) {
        a[k] = L[i++];
      } else {
        a[k] = R[j++];
      }
    }
  }

  public static void qs(card[] a, int n, int p, int r) {
    int q;
    if (p < r) {
      q = partition(a, n, p, r);
      qs(a, n, p, q - 1);
      qs(a, n, q + 1, r);
    }
  }

  public static int partition(card[] a, int n, int p, int r) {
    int i, j;
    card t, x;
    x = a[r];
    i = p - 1;
    for (j = p; j < r; j++) {
      if (a[j].v <= x.v) {
        i++;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
      }
    }
    t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;
    return i + 1;
  }
}

class card {
  char s;
  int v;
  card(char s, int v) {
    this.s = s;
    this.v = v;
  }
}

