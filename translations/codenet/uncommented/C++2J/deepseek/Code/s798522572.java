import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int T = scanner.nextInt();
        int[] A = new int[N];
        ArrayList<Integer> B = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        int m = A[0];
        B.add(A[1] - m);
        m = Math.min(m, A[1]);
        for (int i = 2; i < N; i++) {
            B.add(A[i] - m);
            m = Math.min(m, A[i]);
        }
        int max = Collections.max(B);
        int count = Collections.frequency(B, max);
        System.out.println(count);
    }
}
