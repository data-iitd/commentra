import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int X = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int[] S = IntStream.range(0, N).map(i -> A[i] + (i == 0 ? 0 : S[i - 1])).toArray();
        int ans = Integer.MAX_VALUE;
        for (int k = 1; k <= N / 2; k++) {
            int E = k * X + 2 * IntStream.range(N - 2 * k - 1, -1, -k).map(i -> S[i]).sum();
            ans = Math.min(ans, E);
        }
        System.out.println(ans + N * X + 5 * S[N - 1]);
    }
}

