import java.util.Scanner;

public class CountingSort {
    static final int I = 10000;

    public static void countingSort(int[] a, int[] b, int k) {
        int[] c = new int[I + 1];
        for (int i = 0; i <= I; i++) {
            c[i] = 0;
        }
        for (int j = 0; j < k; j++) {
            c[a[j + 1]]++;
        }
        for (int i = 1; i <= I; i++) {
            c[i] += c[i - 1];
        }
        for (int j = k; j > 0; j--) {
            b[c[a[j]]] = a[j];
            c[a[j]]--;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];

        for (int i = 0; i < n; i++) {
            a[i + 1] = scanner.nextInt();
        }

        countingSort(a, b, n);
        System.out.print(b[1]);
        for (int i = 2; i <= n; i++) {
            System.out.print(" " + b[i]);
        }
        System.out.println();
        scanner.close();
    }
}
// <END-OF-CODE>
