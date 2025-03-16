import java.util.Scanner;

public class Main {
    // Declare global arrays to be used in the quicksort algorithm
    static int[] low = new int[200000];
    static int[] high = new int[200000];

    // Partition function to rearrange elements in array 'a' based on values in array 'b'
    static int part(int[] a, int[] b, int l, int r) {
        int i = l - 1;
        int j = r;
        int x = b[r];
        int t;

        while (true) {
            while (b[++i] < x);
            while (i < --j && x < b[j]);

            if (i >= j) break;

            // Swap elements in array 'a'
            t = a[i]; a[i] = a[j]; a[j] = t;
            // Swap elements in array 'b'
            t = b[i]; b[i] = b[j]; b[j] = t;
        }

        // Swap elements in array 'a' and 'b' to place pivot in the correct position
        t = a[i]; a[i] = a[r]; a[r] = t;
        t = b[i]; b[i] = b[r]; b[r] = t;
        return i;
    }

    // Quicksort function to sort arrays 'a' and 'b' based on values in array 'b'
    static void quicksort(int[] a, int[] b, int n) {
        int l, r, v;
        int sp = 0;

        // Initialize the stack with the first range to be sorted
        low[sp] = 0;
        high[sp] = n - 1;
        sp++;

        while (sp > 0) {
            sp--;
            l = low[sp];
            r = high[sp];

            if (l >= r) continue;

            // Partition the array and get the pivot index
            v = part(a, b, l, r);

            // Push the sub-ranges onto the stack based on the pivot position
            if (v - l < r - v) {
                low[sp] = v + 1;
                high[sp++] = r;
                low[sp] = l;
                high[sp++] = v - 1;
            } else {
                low[sp] = l;
                high[sp++] = v - 1;
                low[sp] = v + 1;
                high[sp++] = r;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, m;
        int cnt = 0;
        int t;

        // Read the number of elements and the number of pairs
        n = scanner.nextInt();
        m = scanner.nextInt();

        int[] a = new int[m];
        int[] b = new int[m];

        // Read the pairs of integers into arrays 'a' and 'b'
        for (int i = 0; i < m; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }

        // Sort the pairs using the quicksort function
        quicksort(a, b, m);

        // Count the number of unique intervals
        t = 0;
        for (int i = 0; i < m; i++) {
            if (t <= a[i]) {
                t = b[i];
                cnt++;
            }
        }

        // Print the count of unique intervals
        System.out.println(cnt);
        scanner.close();
    }
}
// <END-OF-CODE>
