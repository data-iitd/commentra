import java.util.Scanner;

public class SortingStability {
    static final int MAX = 100000;
    static int q;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int[] A = new int[MAX + 1];
        char[] C = new char[MAX + 1];
        char[] MC = new char[MAX + 1];
        int[] MN = new int[MAX + 1];

        int n = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            MC[i] = scanner.next().charAt(0);
            MN[i] = scanner.nextInt();
        }

        for (int i = 1; i <= n; i++) {
            C[i] = MC[i];
            A[i] = MN[i];
        }

        mergeSort(MC, MN, 1, n);
        q = 1;
        quicksort(C, A, q, n);

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (MN[i] == A[i] && MC[i] == C[i]) {
                count++;
            }
        }

        if (count == n) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }

        for (int i = 1; i <= n; i++) {
            System.out.println(C[i] + " " + A[i]);
        }

        scanner.close();
    }

    static int partition(char[] C, int[] A, int p, int r) {
        int i = p - 1;
        char x = C[r];
        int y = A[r];

        for (int j = p; j < r; j++) {
            if (A[j] <= y) {
                i++;
                swap(A, C, i, j);
            }
        }
        swap(A, C, i + 1, r);
        return i + 1;
    }

    static void quicksort(char[] C, int[] A, int p, int r) {
        if (p < r) {
            q = partition(C, A, p, r);
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

        int i = 1, j = 1;
        for (int k = left; k <= right; k++) {
            if (LN[i] <= RN[j]) {
                MN[k] = LN[i];
                MC[k] = LC[i++];
            } else {
                MN[k] = RN[j];
                MC[k] = RC[j++];
            }
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

    static void swap(int[] A, char[] C, int i, int j) {
        int tempN = A[i];
        A[i] = A[j];
        A[j] = tempN;

        char tempC = C[i];
        C[i] = C[j];
        C[j] = tempC;
    }
}
// <END-OF-CODE>
