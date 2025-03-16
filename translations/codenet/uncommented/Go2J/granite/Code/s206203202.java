
import java.util.Scanner;

public class s206203202{
    public static int Abs(int x) {
        if (x < 0) {
            return -x;
        }
        return x;
    }

    public static int min(int a, int b) {
        if (a > b) {
            return b;
        }
        return a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        // int mini = 999999999;
        // boolean[] hm = new boolean[N + 1];
        // hm[N] = true;
        // while (!hm[K]) {
        //     hm[K] = true;
        //     K = Abs(K - N);
        // }
        // for (int k = 0; k <= N; k++) {
        //     if (hm[k]) {
        //         mini = min(mini, k);
        //     }
        // }
        // System.out.println(mini);

        int x = N % K;
        x = min(Abs(x - K), x);
        System.out.println(x);
    }
}

