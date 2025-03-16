import java.util.Scanner;
import java.util.Vector;
import java.util.Collections;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int T = sc.nextInt();
        int[] A = new int[N];
        Vector<Integer> B = new Vector<Integer>();
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        int m = A[0];
        B.add(A[1] - m);
        m = Math.min(m, A[1]);
        for (int i = 2; i < N; i++) {
            B.add(A[i] - m);
            m = Math.min(m, A[i]);
        }

        int max_value = Collections.max(B);
        System.out.println(Collections.frequency(B, max_value));
    }
}

