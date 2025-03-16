
import java.util.*;
import java.io.*;

class atcoder_AGC003_C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(br.readLine()) * N + i;
        }
        Arrays.sort(A);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            int d = (A[i] % N) % 2;
            if (d % 2!= i % 2) {
                cnt++;
            }
        }
        System.out.println(cnt / 2);
    }
}
