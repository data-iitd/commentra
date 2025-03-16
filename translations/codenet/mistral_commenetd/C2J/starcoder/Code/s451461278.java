
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] C = new char[n + 1];
        int[] A = new int[n + 1];
        char[] MC = new char[n + 1];
        int[] MN = new int[n + 1];
        int i, p, count = 0;

        for (i = 1; i <= n; i++) {
            C[i] = sc.next().charAt(0);
            A[i] = sc.nextInt();
        }

        for (i = 1; i <= n; i++) {
            MC[i] = C[i];
            MN[i] = A[i];
        }

        Merge_Sort(MC, MN, 1, n);

        p = 1;
        Quicksort(C, A, p, n);

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

    public static void Merge(char MC[], int MN[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int[] LN = new int[n1 + 2];
        int[] RN = new int[n2 + 2];
        int[] LC = new int[n1 + 2];
        int[] RC = new int[n2 + 2];

        for (int i = 1; i <= n1; i++) {
            LN[i] = MN[left + i - 1];
            LC[i] = MC[left + i - 1];
        }

        for (int i = 1; i <= n2; i++) {
            RN[i] = MN[mid + i];
            RC[i] = MC[mid + i];
        }

        LN[n1 + 1] = 1000000000;
        RN[n2 + 1] = 1000000000;

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

        free(LN);
        free(RN);
        free(LC);
        free(RC);
    }

    public static void Merge_Sort(char MC[], int MN[], int left, int right) {
        int mid;
        if (left < right) {
            mid = (left + right) / 2;
            Merge_Sort(MC, MN, left, mid);
            Merge_Sort(MC, MN, mid + 1, right);
            Merge(MC, MN, left, mid, right);
        }
    }

    public static void Quicksort(char C[], int A[], int p, int r) {
        if (p < r) {
            int q = Partition(C, A, p, r);
            Quicksort(C, A, p, q - 1);
            Quicksort(C, A, q + 1, r);
        }
    }

    public static int Partition(char C[], int A[], int p, int r) {
        int i, j;
        char tmpC, x;
        int tmpN, y;

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
}

