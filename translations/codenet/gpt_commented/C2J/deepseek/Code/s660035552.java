public class IntervalScheduling {
    public static void main(String[] args) {
        // Read the number of intervals and pairs
        int n, m;
        // Read the intervals into arrays a and b
        int[] a = new int[100006];
        int[] b = new int[100006];
        int cnt = 0;
        int t = 0;

        // Read the number of intervals and pairs
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Read the intervals into arrays a and b
        for (int i = 0; i < m; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
        }

        // Sort the intervals based on their end points using quicksort
        quicksort(a, b, m);

        // Initialize the end of the last added interval
        t = 0;
        // Count the maximum number of non-overlapping intervals
        for (int i = 0; i < m; i++) {
            // If the start of the current interval is greater than or equal to the end of the last added interval
            if (t <= a[i]) {
                t = b[i]; // Update the end to the current interval's end
                cnt++; // Increment the count of non-overlapping intervals
            }
        }

        // Output the count of non-overlapping intervals
        System.out.println(cnt);
    }

    // Function to partition the arrays based on the quicksort algorithm
    public static int part(int[] a, int[] b, int l, int r) {
        int i, j, x, t;

        // Initialize pointers for partitioning
        i = l - 1;
        j = r;

        // Choose the pivot element from the end of the array
        x = b[r];

        // Partitioning process
        while (true) {
            // Move the left pointer to the right until an element greater than or equal to the pivot is found
            while (b[++i] < x);
            // Move the right pointer to the left until an element less than or equal to the pivot is found
            while (i < --j && x < b[j]);

            // If the pointers have crossed, exit the loop
            if (i >= j) break;

            // Swap elements in both arrays to ensure correct partitioning
            t = a[i]; a[i] = a[j]; a[j] = t;
            t = b[i]; b[i] = b[j]; b[j] = t;
        }

        // Place the pivot element in its correct position
        t = a[i]; a[i] = a[r]; a[r] = t;
        t = b[i]; b[i] = b[r]; b[r] = t;
        return i; // Return the index of the pivot
    }

    // Function to perform quicksort on two arrays
    public static void quicksort(int[] a, int[] b, int n) {
        int l, r, v;
        int[] low = new int[200000];
        int[] high = new int[200000];
        int sp = 0;

        // Initialize the stack for iterative quicksort
        low[0] = 0;
        high[0] = n - 1;
        sp = 1;

        // Iterative quicksort using a stack
        while (sp > 0) {
            sp--; // Decrement stack pointer
            l = low[sp]; // Get the current low index
            r = high[sp]; // Get the current high index

            // If the subarray has one or no elements, skip sorting
            if (l >= r) continue;

            // Partition the array and get the pivot index
            v = part(a, b, l, r);

            // Decide which side to process next based on size
            if (v - l < r - v) {
                low[sp] = v + 1; // Right side
                high[sp++] = r;
                low[sp] = l; // Left side
                high[sp++] = v - 1;
            } else {
                low[sp] = l; // Left side
                high[sp++] = v - 1;
                low[sp] = v + 1; // Right side
                high[sp++] = r;
            }
        }
    }
}
