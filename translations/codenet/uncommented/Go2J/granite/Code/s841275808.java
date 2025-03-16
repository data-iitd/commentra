
import java.util.*;

public class s841275808{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] X = new int[N];
        int[] Y = new int[N];
        for (int i = 0; i < N; i++) {
            X[i] = scanner.nextInt();
            Y[i] = X[i];
        }
        Arrays.sort(Y);
        int m1 = Y[N / 2 - 1];
        int m2 = Y[N / 2];
        for (int i = 0; i < N; i++) {
            if (X[i] <= m1) {
                System.out.println(m2);
            } else {
                System.out.println(m1);
            }
        }
    }
}

