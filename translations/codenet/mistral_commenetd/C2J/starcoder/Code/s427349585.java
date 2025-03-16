
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] s = new String[n];
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.next();
            v[i] = sc.nextInt();
        }
        Card[] a = new Card[n];
        Card[] b = new Card[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Card(s[i].charAt(0), v[i]);
            b[i] = new Card(s[i].charAt(0), v[i]);
        }
        mergeSort(a, 0, n - 1);
        quickSort(b, 0, n - 1);
        boolean stable = true;
        for (int i = 0; i < n; i++) {
            if (a[i].c!= b[i].c) {
                stable = false;
            }
        }
        if (stable) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }
        for (int i = 0; i < n; i++) {
            System.out.println(b[i].c + " " + b[i].v);
        }
    }

    public static void mergeSort(Card[] a, int p, int r) {
        if (p < r) {
            int m = (p + r) / 2;
            mergeSort(a, p, m);
            mergeSort(a, m + 1, r);
            merge(a, p, m, r);
        }
    }

    public static void merge(Card[] a, int p, int m, int r) {
        int n1 = m - p + 1;
        int n2 = r - m;
        Card[] L = new Card[n1 + 2];
        Card[] R = new Card[n2 + 2];
        for (int i = 0; i < n1; i++) {
            L[i] = a[p + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = a[m + i + 1];
        }
        L[n1] = new Card(' ', 2000000000);
        R[n2] = new Card(' ', 2000000000);
        int i = 0, j = 0, k = p;
        while (k <= r) {
            if (L[i].v <= R[j].v) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
            }
            k++;
        }
    }

    public static void quickSort(Card[] a, int p, int r) {
        if (p < r) {
            int q = partition(a, p, r);
            quickSort(a, p, q - 1);
            quickSort(a, q + 1, r);
        }
    }

    public static int partition(Card[] a, int p, int r) {
        Card x = a[r];
        int i = p - 1;
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
}

class Card {
    char c;
    int v;

    public Card(char c, int v) {
        this.c = c;
        this.v = v;
    }
}

