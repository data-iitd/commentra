import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();

        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }

        Arrays.sort(A);

        int ans = 0;
        int i = 0, j = 0;
        while (j < A.length) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
                i++;
            } else {
                j++;
            }
        }

        if (x > 0 && A.length == ans) {
            ans--;
        }

        System.out.println(ans);
    }
}
// <END-OF-CODE>
