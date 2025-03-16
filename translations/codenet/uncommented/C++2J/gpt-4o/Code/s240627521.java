import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long[] A = new long[N];
        for (int i = 0; i < N; ++i) {
            A[i] = scanner.nextLong();
        }
        Arrays.sort(A);
        long max = Long.MAX_VALUE;
        int index = -1;
        for (int i = N - 2; i >= 0; --i) {
            if (max > Math.abs(A[N - 1] - 2 * A[i])) {
                max = Math.abs(A[N - 1] - 2 * A[i]);
                index = i;
            }
        }
        System.out.println(A[N - 1] + " " + A[index]);
    }
}

// <END-OF-CODE>
