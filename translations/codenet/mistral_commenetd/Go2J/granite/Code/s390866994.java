

import java.util.*;

public class s390866994{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();

        int[] t = new int[N];
        for (int i = 0; i < N; i++) {
            t[i] = sc.nextInt();
        }

        Arrays.sort(t);

        int ans = 1;
        int cnt = 1;
        int end = t[0] + K;

        for (int i = 1; i < N; i++) {
            if (cnt < C && t[i] <= end) {
                cnt++;
            } else {
                cnt = 1;
                end = t[i] + K;
                ans++;
            }
        }

        System.out.println(ans);
    }
}

