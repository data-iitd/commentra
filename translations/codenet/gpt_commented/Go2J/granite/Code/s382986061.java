
import java.util.Scanner;

public class s382986061{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] as = new int[N + 1];
        for (int i = 0; i < K; i++) {
            int d = scanner.nextInt();
            for (int j = 0; j < d; j++) {
                int a = scanner.nextInt();
                as[a]++;
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (as[i] == 0) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
