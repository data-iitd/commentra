public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (true) {
            int n = scanner.nextInt();
            int r = scanner.nextInt();
            if (n == 0 && r == 0) {
                break;
            }
            int[] a = new int[51];
            int[] b = new int[51];
            for (int i = 0; i < n; i++) {
                a[i] = i + 1;
            }
            for (int i = 0; i < r; i++) {
                int p = scanner.nextInt();
                int c = scanner.nextInt();
                for (int j = 0; j < c; j++) {
                    b[j] = a[n - p - c + 1 + j];
                }
                for (int j = 0; j < p - 1; j++) {
                    a[n - p + j + 1] = a[n - p + j];
                }
                for (int j = n - p - c + 1, k = 0; k < c; j++, k++) {
                    a[j] = b[k];
                }
                System.out.println(a[n - 1]);
            }
        }
    }
}
