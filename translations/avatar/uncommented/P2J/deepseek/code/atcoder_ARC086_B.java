import java.util.*;

public class Main {
    static int mod = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = scanner.nextInt();
        }
        scanner.close();

        int maxVal = 0;
        int maxSign = 0;
        int maxIndex = -1;
        for (int i = 0; i < N; i++) {
            if (Math.abs(a[i]) > maxVal) {
                maxVal = Math.abs(a[i]);
                maxSign = Integer.compare(a[i], 0);
                maxIndex = i;
            }
        }

        if (maxSign == 0) {
            System.out.println(0);
        } else if (maxSign == 1) {
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((maxIndex + 1) + " " + (i + 1));
            }
            for (int i = 0; i < N - 1; i++) {
                System.out.println((i + 1) + " " + (i + 2));
            }
        } else {
            System.out.println(2 * N - 1);
            for (int i = 0; i < N; i++) {
                System.out.println((maxIndex + 1) + " " + (i + 1));
            }
            for (int i = N - 1; i > 0; i--) {
                System.out.println((i + 1) + " " + i);
            }
        }
    }
}
