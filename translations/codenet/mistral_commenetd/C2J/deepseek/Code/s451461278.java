public class StableSort {
    static final int MAX = 100000;

    // Function declarations
    static int partition(char[] C, int[] A, int p, int r) {
        int i, j;
        char tmpC;
        int tmpN;
        char x = C[r];
        int y = A[r];
        i = p - 1;
        for (j = p; j < r; j++) {
            if (A[j] <= y) {
                i = i + 1;
                tmpN = A[j];
                tmpC = C[j];
                A[j] = A[i];
                C[j] = C[i];
                A[i] = tmpN;
                C[i] = tmpC;
            }
        }
        tmpN = A[i + 1];
        tmpC = C[i + 1];
        A[i + 1] = A[r];
        C[i + 1] = C[r];
        A[r] = tmpN;
        C[r] = tmpC;
        return i + 1;
    }

    static void quicksort(char[] C, int[] A, int p, int r) {
        if (p < r) {
            int q = partition(C, A, p, r);
            quicksort(C, A, p, q - 1);
            quicksort(C, A, q + 1, r);
        }
    }

    static void merge(char[] MC, int[] MN, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int[] LN = new int[n1 + 1];
        int[] RN = new int[n2 + 1];
        char[] LC = new char[n1 + 1];
        char[] RC = new char[n2 + 1];
        for (int i = 1; i <= n1; i++) {
            LN[i] = MN[left + i - 1];
            LC[i] = MC[left + i - 1];
        }
        for (int i = 1; i <= n2; i++) {
            RN[i] = MN[mid + i];
            RC[i] = MC[mid + i];
        }
        LN[n1 + 1] = Integer.MAX_VALUE;
        RN[n2 + 1] = Integer.MAX_VALUE;
        int i = 1, j = 1, k = left;
        while (i <= n1 && j <= n2) {
            if (LN[i] <= RN[j]) {
                MN[k] = LN[i];
                MC[k] = LC[i];
                i++;
            } else {
                MN[k] = RN[j];
                MC[k] = RC[j];
                j++;
            }
            k++;
        }
    }

    static void mergeSort(char[] MC, int[] MN, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(MC, MN, left, mid);
            mergeSort(MC, MN, mid + 1, right);
            merge(MC, MN, left, mid, right);
        }
    }

    public static void main(String[] args) {
        int[] A = new int[MAX + 1];
        char[] C = new char[MAX + 1];
        char[] MC = new char[MAX + 1];
        int[] MN = new int[MAX + 1];
        int i, p, n;
        int count = 0;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        for (i = 1; i <= n; i++) {
            C[i] = scanner.next().charAt(0);
            A[i] = scanner.nextInt();
        }
        for (i = 1; i <= n; i++) {
            MC[i] = C[i];
            MN[i] = A[i];
        }
        mergeSort(MC, MN, 1, n);
        p = 1;
        quicksort(C, A, p, n);
        for (i = 1; i <= n; i++) {
            if (MN[i] == A[i] && MC[i] == C[i])
                count++;
        }
        if (count == n)
            System.out.println("Stable");
        else
            System.out.println("Not stable");
        for (i = 1; i <= n; i++) {
            System.out.println(C[i] + " " + A[i]);
        }
    }
}
