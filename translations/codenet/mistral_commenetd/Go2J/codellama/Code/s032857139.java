
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }

        int ans = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
                i++;
            } else {
                j++;
            }
        }

        if (x > 0 && n == ans) {
            ans--;
        }

        System.out.println(ans);
    }
}

