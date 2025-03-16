
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int mn = N + 1, mx = -1;
        for (int i = 0; i < N; i++) {
            if (i + 1 != A[i]) {
                mn = Math.min(mn, i);
                mx = Math.max(mx, i);
            }
        }
        if (mx == -1) {
            System.out.println("0 0");
        } else {
            A = A.clone();
            for (int i = mn; i < mx + 1; i++) {
                A[i] = A[i + 1];
            }
            for (int i = mx + 1; i < N; i++) {
                A[i] = A[i - 1];
            }
            if (java.util.Arrays.equals(A, java.util.Arrays.sort(A))) {
                System.out.println(mn + 1 + " " + mx + 1);
            } else {
                System.out.println("0 0");
            }
        }
    }
}

