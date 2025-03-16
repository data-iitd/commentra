import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = in.nextInt();
        }

        int answer = 0;
        // Calculate the maximum absolute difference between any two elements in the array
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int diff = Math.abs(A[i] - A[j]);
                answer = Math.max(answer, diff);
            }
        }
        // Output the result
        System.out.println(answer);
    }
}
