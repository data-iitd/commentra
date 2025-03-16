
import java.util.Scanner;

public class s451461278{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] c = new char[n];
        int[] a = new int[n];
        char[] mc = new char[n];
        int[] mn = new int[n];
        int count = 0;

        for (int i = 1; i <= n; i++) {
            c[i] = sc.next().charAt(0);
            a[i] = sc.nextInt();
            mc[i] = c[i];
            mn[i] = a[i];
        }

        mergeSort(mc, mn, 1, n);
        quickSort(c, a, 1, n);

        for (int i = 1; i <= n; i++) {
            if (mn[i] == a[i] && mc[i] == c[i]) {
                count++;
            }
        }

        if (count == n) {
            System.out.println("Stable");
        } else {
            System.out.println("Not stable");
        }

        for (int i = 1; i <= n; i++) {
            System.out.println(c[i] + " " + a[i]);
        }
    }

    public static void merge(char[] mc, int[] mn, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int[] ln = new int[n1 + 1];
        int[] rn = new int[n2 + 1];
        char[] lc = new char[n1 + 1];
        char[] rc = new char[n2 + 1];

        for (int i = 1; i <= n1; i++) {
            ln[i] = mn[left + i - 1];
            lc[i] = mc[left + i - 1];
        }

        for (int i = 1; i <= n2; i++) {
            rn[i] = mn[mid + i];
            rc[i] = mc[mid + i];
        }

        ln[n1 + 1] = 1000000000;
        rn[n2 + 1] = 1000000000;

        int i = 1;
        int j = 1;

        for (int k = left; k <= right; k++) {
            if (ln[i] <= rn[j]) {
                mn[k] = ln[i];
                mc[k] = lc[i++];
            } else {
                mn[k] = rn[j];
                mc[k] = rc[j++];
            }
        }
    }

    public static void mergeSort(char[] mc, int[] mn, int left, int right) {
        int mid;

        if (left < right) {
            mid = (left + right) / 2;
            mergeSort(mc, mn, left, mid);
            mergeSort(mc, mn, mid + 1, right);
            merge(mc, mn, left, mid, right);
        }
    }

    public static void quickSort(char[] c, int[] a, int p, int r) {
        if (p < r) {
            int q = partition(c, a, p, r);
            quickSort(c, a, p, q - 1);
            quickSort(c, a, q + 1, r);
        }
    }

    public static int partition(char[] c, int[] a, int p, int r) {
        int x = c[r];
        int y = a[r];
        int i = p - 1;

        for (int j = p; j < r; j++) {
            if (a[j] <= y) {
                i = i + 1;
                int tempN = a[j];
                char tempC = c[j];
                a[j] = a[i];
                c[j] = c[i];
                a[i] = tempN;
                c[i] = tempC;
            }
        }

        int tempN = a[i + 1];
        char tempC = c[i + 1];
        a[i + 1] = a[r];
        c[i + 1] = c[r];
        a[r] = tempN;
        c[r] = tempC;

        return i + 1;
    }
}

