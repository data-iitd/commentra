import java.util.*;

public class CountingSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        for (int i = 0; i < n; i++) {
            a[i + 1] = sc.nextInt();
        }
        countingSort(a, b, n);
        System.out.print(b[1]);
        for (int i = 2; i < n + 1; i++) {
            System.out.print(" " + b[i]);
        }
        System.out.println();
    }

    public static void countingSort(int[] a, int[] b, int n) {
        int[] c = new int[I + 1];
        for (int i = 0; i <= I; i++) {
            c[i] = 0;
        }
        for (int j = 0; j < n; j++) {
            c[a[j + 1]]++;
        }
        for (int i = 1; i <= I; i++) {
            c[i] += c[i - 1];
        }
        for (int j = n; j > 0; j--) {
            b[c[a[j]]] = a[j];
            c[a[j]]--;
        }
    }
}
