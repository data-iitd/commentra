public class CountingSort {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n + 1];
        int[] b = new int[n + 1];
        for (int i = 0; i < n; i++) {
            a[i + 1] = scanner.nextInt();
        }
        CountingSort(a, b, n);
        System.out.print(b[1]);
        for (int i = 2; i < n + 1; i++) {
            System.out.print(" " + b[i]);
        }
        System.out.println();
    }

    public static void CountingSort(int[] a, int[] b, int k) {
        int[] c = new int[10001];
        for (int i = 0; i <= 10000; i++) {
            c[i] = 0;
        }
        for (int j = 0; j < k; j++) {
            c[a[j + 1]]++;
        }
        for (int i = 1; i < 10001; i++) {
            c[i] += c[i - 1];
        }
        for (int j = k; j > 0; j--) {
            b[c[a[j]]] = a[j];
            c[a[j]]--;
        }
    }
}
