import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long k = scanner.nextLong();
        int q = scanner.nextInt();
        int[] a = new int[q];
        long[] point = new long[100001];

        // 初期化
        for (int i = 0; i < n; i++) {
            point[i] = k;
        }

        for (int i = 0; i < q; i++) {
            a[i] = scanner.nextInt();
            point[a[i] - 1]++;
        }

        for (int i = 0; i < n; i++) {
            if (point[i] - (q - point[i]) > 0) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}
