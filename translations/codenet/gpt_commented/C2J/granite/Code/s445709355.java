
// ABC 152-D
// 2020.1.19 bal4u

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class s445709355{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] f1 = new int[100];
        int[] f2 = new int[100];
        for (int i = N; i > 0; i--) {
            int k = i % 10;
            int n = i;
            while (n >= 10) n /= 10;
            f1[10 * k + n]++;
            f2[n * 10 + k]++;
        }
        int ans = 0;
        for (int i = 0; i < 100; i++) ans += f1[i] * f2[i];
        System.out.println(ans);
    }
}

