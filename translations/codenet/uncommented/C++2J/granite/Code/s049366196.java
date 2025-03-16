
import java.io.*;
import java.util.*;

class s049366196 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        long ans = 1;
        for (int i = 2; i <= N; i++) {
            if (isPrime(i)) {
                int NN = N;
                int cnt = 0;
                while (NN > 0) {
                    cnt += NN / i;
                    NN /= i;
                }
                ans *= cnt + 1;
                ans %= 100000007;
            }
        }

        System.out.println(ans);
    }

    public static boolean isPrime(int x) {
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
}

