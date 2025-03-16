
import java.util.*;
import java.io.*;

class s462906333 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int X = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int[] V = new int[N];
        for (int i = 0; i < N; i++) {
            V[i] = A[i];
        }
        int ans = Integer.MAX_VALUE;
        for (int k = 0; k < N; k++) {
            int kans = 0;
            for (int i = 0; i < N; i++) {
                if (i - k < 0) {
                    V[i] = Math.min(V[i], A[N + i - k]);
                } else {
                    V[i] = Math.min(V[i], A[i - k]);
                }
                kans += V[i];
            }
            ans = Math.min(ans, kans + k * X);
        }
        System.out.println(ans);
    }
}

