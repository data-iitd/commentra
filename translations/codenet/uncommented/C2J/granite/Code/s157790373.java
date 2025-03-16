
import java.util.Scanner;

public class s157790373{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int M = scanner.nextInt();
            boolean flag = false;
            solve(-1, M, A);
            if (flag) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }

    public static void solve(int i, int m, int[] A) {
        if (i > A.length) {
            return;
        }
        if (m < 0) {
            return;
        }
        if (m == 0 || m - A[i + 1] == 0) {
            flag = true;
            return;
        }
        solve(i + 1, m, A);
        solve(i + 1, m - A[i], A);
    }
}

