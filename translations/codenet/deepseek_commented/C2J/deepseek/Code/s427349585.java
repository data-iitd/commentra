public class Main {
    // Define the card class
    static class Card {
        char s;
        int v;

        Card(char s, int v) {
            this.s = s;
            this.v = v;
        }
    }

    // Merge function to merge two subarrays
    static void merge(Card[] a, int n, int l, int m, int r) {
        int i, j, k;
        int n1 = m - l;
        int n2 = r - m;

        // Create temporary arrays
        Card[] L = new Card[n1 + 1];
        Card[] R = new Card[n2 + 1];

        // Copy data to temp arrays
        for (i = 0; i < n1; i++) L[i] = a[l + i];
        for (i = 0; i < n2; i++) R[i] = a[m + i];

        // Sentinel value
        L[n1] = new Card(' ', 2000000000);
        R[n2] = new Card(' ', 2000000000);

        i = 0;
        j = 0;

        // Merge the two subarrays
        for (k = l; k < r; k++) {
            if (L[i].v <= R[j].v) {
                a[k] = L[i++];
            } else {
                a[k] = R[j++];
            }
        }
    }

    // Merge sort function to sort the array
    static void mergeSort(Card[] a, int n, int l, int r) {
        if (l + 1 < r) {
            int m = (l + r) / 2;
            mergeSort(a, n, l, m);
            mergeSort(a, n, m, r);
            merge(a, n, l, m, r);
        }
    }

    // Partition function to partition the array around a pivot
    static int partition(Card[] a, int n, int p, int r) {
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

    // Quick sort function to sort the array
    static void quickSort(Card[] a, int n, int p, int r) {
        if (p < r) {
            int q = partition(a, n, p, r);
            quickSort(a, n, p, q - 1);
            quickSort(a, n, q + 1, r);
        }
    }

    // Main function to read input, sort the arrays, check for stability, and print the result
    public static void main(String[] args) {
        int n;
        Card[] a = new Card[200000];
        Card[] b = new Card[200000];
        boolean stable = true;

        // Read the number of cards
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();

        // Read each card's suit and value
        for (int i = 0; i < n; i++) {
            String s = scanner.next();
            int v = scanner.nextInt();
            a[i] = new Card(s.charAt(0), v);
            b[i] = new Card(s.charAt(0), v);
        }

        // Sort the array using merge sort
        mergeSort(a, n, 0, n);

        // Sort the array using quick sort
        quickSort(b, n, 0, n - 1);

        // Check if the sorting is stable
        for (int i = 0; i < n; i++) {
            if (a[i].s != b[i].s) {
                stable = false;
                break;
            }
        }

        // Print the stability status
        if (stable) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }

        // Print the sorted array
        for (int i = 0; i < n; i++) {
            System.out.println(b[i].s + " " + b[i].v);
        }
    }
}
