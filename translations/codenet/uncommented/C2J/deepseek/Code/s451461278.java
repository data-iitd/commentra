public class StableSort {
    static int MAX = 100000;
    static int q;

    public static void main(String[] args) {
        int[] A = new int[MAX + 1];
        char[] C = new char[MAX + 1];
        char[] MC = new char[MAX + 1];
        int[] MN = new int[MAX + 1];

        int i, p, n;
        int count = 0;

        java.util.Scanner scanner = new java.util.Scanner(System.in);
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
        quickSort(C, A, p, n);

        for (i = 1; i <= n; i++) {
            if (MN[i] == A[i] && MC[i] == C[i])
                count++;
        }

        if (count == n)
            System.out.println("Stable");
        else
            System.out.println("Not stable");

        for (i = 1; i <= n; i++)
            System.out.println(C[i] + " " + A[i]);
    }

    public static int partition(char[] C, int[] A, int p, int r) {
        int i, j;
        char tmpC;
        int tmpN;
        char x;
        int y;

        x = C[r];
        y = A[r];
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

    public static void quickSort(char[] C, int[] A, int p, int r) {
        if (p < r) {
            q = partition(C, A, p, r);
            quickSort(C, A, p, q - 1);
            quickSort(C, A, q + 1, r);
        }
    }

    public static void merge(char[] MC, int[] MN, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int[] LN = new int[n1 + 1];
        int[] RN = new int[n2 + 1];
        char[] LC = new char[n1 + 1];
        char[] RC = new char[n2 + 1];

        int i, j, k;

        for (i = 1; i <= n1; i++) {
            LN[i] = MN[left + i - 1];
            LC[i] = MC[left + i - 1];
        }

        for (i = 1; i <= n2; i++) {
            RN[i] = MN[mid + i];
            RC[i] = MC[mid + i];
        }

        LN[n1 + 1] = Integer.MAX_VALUE;
        RN[n2 + 1] = Integer.MAX_VALUE;

        i = 1;
        j = 1;

        for (k = left; k <= right; k++) {
            if (LN[i] <= RN[j]) {
                MN[k] = LN[i];
                MC[k] = LC[i++];
            } else {
                MN[k] = RN[j];
                MC[k] = RC[j++];
            }
        }
    }

    public static void mergeSort(char[] MC, int[] MN, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(MC, MN, left, mid);
            mergeSort(MC, MN, mid + 1, right);
            merge(MC, MN, left, mid, right);
        }
    }
}
