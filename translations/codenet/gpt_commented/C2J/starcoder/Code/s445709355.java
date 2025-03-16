// ABC 152-D
// 2020.1.19 bal4u

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int f1[] = new int[100], f2[] = new int[100];
        int ans = 0;
        for (int i = 0; i < 100; ++i) f1[i] = f2[i] = 0;
        while (N > 0) {
            int n = N % 10;
            while (N >= 10) N /= 10;
            ++f1[10*n + N];
            ++f2[N*10 + n];
            --N;
        }
        for (int i = 0; i < 100; ++i) ans += f1[i] * f2[i];
        System.out.println(ans);
    }
}

