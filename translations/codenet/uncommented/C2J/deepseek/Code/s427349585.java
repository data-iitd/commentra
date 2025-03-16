public class Main {
    static class Card implements Comparable<Card> {
        char s;
        int v;

        Card(char s, int v) {
            this.s = s;
            this.v = v;
        }

        @Override
        public int compareTo(Card other) {
            return Integer.compare(this.v, other.v);
        }
    }

    public static void merge(Card[] a, int l, int m, int r) {
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
        L[n1] = new Card(' ', 2000000000);
        R[n2] = new Card(' ', 2000000000);

        int i = 0, j = 0;
        for (int k = l; k < r; k++) {
            if (L[i].compareTo(R[j]) <= 0) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
            }
        }
    }

    public static void mergeSort(Card[] a, int l, int r) {
        if (l + 1 < r) {
            int m = (l + r) / 2;
            mergeSort(a, l, m);
            mergeSort(a, m, r);
            merge(a, l, m, r);
        }
    }

    public static int partition(Card[] a, int p, int r) {
        Card x = a[r];
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (a[j].compareTo(x) <= 0) {
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

    public static void quickSort(Card[] a, int p, int r) {
        if (p < r) {
            int q = partition(a, p, r);
            quickSort(a, p, q - 1);
            quickSort(a, q + 1, r);
        }
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        Card[] a = new Card[200000];
        Card[] b = new Card[200000];

        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            int v = scanner.nextInt();
            a[i] = new Card(s.charAt(0), v);
            b[i] = new Card(s.charAt(0), v);
        }

        mergeSort(a, 0, n);
        quickSort(b, 0, n - 1);

        boolean stable = true;
        for (int i = 0; i < n; i++) {
            if (a[i].s != b[i].s) {
                stable = false;
                break;
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
}
