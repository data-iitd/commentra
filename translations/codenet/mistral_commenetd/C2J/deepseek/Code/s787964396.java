public class CountingSort {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        int max = 0;

        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
            if (a[i] > max) {
                max = a[i];
            }
        }

        countingSort(a, b, n, max);

        System.out.print(b[1]);
        for (int i = 2; i <= n; i++) {
            System.out.print(" " + b[i]);
        }
        System.out.println();
    }

    public static void countingSort(int[] a, int[] b, int k, int max) {
        int[] c = new int[max + 1];

        for (int i = 0; i <= max; i++) {
            c[i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            c[a[j]]++;
        }

        for (int i = 1; i <= max; i++) {
            c[i] += c[i - 1];
        }

        for (int j = k; j >= 1; j--) {
            b[c[a[j]]] = a[j];
            c[a[j]]--;
        }
    }
}
