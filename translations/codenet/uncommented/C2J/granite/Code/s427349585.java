
import java.util.Scanner;

class s427349585 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Card[] a = new Card[n];
        Card[] b = new Card[n];
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            int v = scanner.nextInt();
            a[i] = new Card(s, v);
            b[i] = new Card(s, v);
        }
        mergeSort(a, 0, n);
        quickSort(b, 0, n - 1);
        if (isStable(a, b)) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }
        for (int i = 0; i < n; i++) {
            System.out.println(b[i].s + " " + b[i].v);
        }
    }

    static void mergeSort(Card[] a, int l, int r) {
        if (l + 1 < r) {
            int m = (l + r) / 2;
            mergeSort(a, l, m);
            mergeSort(a, m, r);
            merge(a, l, m, r);
        }
    }

    static void merge(Card[] a, int l, int m, int r) {
        int n1 = m - l;
        int n2 = r - m;
        Card[] L = new Card[n1 + 1];
        Card[] R = new Card[n2 + 1];
        for (int i = 0; i < n1; i++) {
            L[i] = a[l + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = a[m + i];
        }
        L[n1] = new Card("", 2000000000L);
        R[n2] = new Card("", 2000000000L);
        int i = 0, j = 0;
        for (int k = l; k < r; k++) {
            if (L[i].v <= R[j].v) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
            }
        }
    }

    static void quickSort(Card[] a, int p, int r) {
        if (p < r) {
            int q = partition(a, p, r);
            quickSort(a, p, q - 1);
            quickSort(a, q + 1, r);
        }
    }

    static int partition(Card[] a, int p, int r) {
        int i = p - 1;
        Card x = a[r];
        for (int j = p; j < r; j++) {
            if (a[j].v <= x.v) {
                i++;
                Card t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        Card t = a[i + 1];
        a[i + 1] = a[r];
        a[r] = t;
        return i + 1;
    }

    static boolean isStable(Card[] a, Card[] b) {
        for (int i = 0; i < a.length; i++) {
            if (!a[i].s.equals(b[i].s)) {
                return false;
            }
        }
        return true;
    }
}

class Card {
    String s;
    long v;

    public Card(String s, long v) {
        this.s = s;
        this.v = v;
    }
}

