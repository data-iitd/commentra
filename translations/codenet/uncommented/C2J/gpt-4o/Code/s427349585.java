import java.util.Scanner;

class Card {
    char s;
    int v;

    Card(char s, int v) {
        this.s = s;
        this.v = v;
    }
}

public class Main {
    static Card[] L = new Card[50002];
    static Card[] R = new Card[50002];

    static void merge(Card[] a, int l, int m, int r) {
        int n1 = m - l;
        int n2 = r - m;

        for (int i = 0; i < n1; i++) {
            L[i] = a[l + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = a[m + i];
        }
        L[n1] = new Card('\0', Integer.MAX_VALUE);
        R[n2] = new Card('\0', Integer.MAX_VALUE);

        int i = 0, j = 0;
        for (int k = l; k < r; k++) {
            if (L[i].v <= R[j].v) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
            }
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

    static int partition(Card[] a, int p, int r) {
        Card x = a[r];
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (a[j].v <= x.v) {
                i++;
                Card temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        Card temp = a[i + 1];
        a[i + 1] = a[r];
        a[r] = temp;
        return i + 1;
    }

    static void quickSort(Card[] a, int p, int r) {
        if (p < r) {
            int q = partition(a, p, r);
            quickSort(a, p, q - 1);
            quickSort(a, q + 1, r);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Card[] a = new Card[n];
        Card[] b = new Card[n];
        boolean stable = true;

        for (int i = 0; i < n; i++) {
            char s = scanner.next().charAt(0);
            int v = scanner.nextInt();
            a[i] = new Card(s, v);
            b[i] = new Card(s, v);
        }

        mergeSort(a, 0, n);
        quickSort(b, 0, n - 1);

        for (int i = 0; i < n; i++) {
            if (a[i].s != b[i].s) {
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

        scanner.close();
    }
}
//<END-OF-CODE>
