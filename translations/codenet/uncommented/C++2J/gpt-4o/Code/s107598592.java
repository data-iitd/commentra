import java.util.Arrays;
import java.util.Scanner;

public class Main {
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

        int y = Y[N / 2];
        for (int i = 0; i < N; i++) {
            if (X[i] < Y[N / 2]) {
                System.out.println(Y[N / 2]);
            } else {
                System.out.println(Y[N / 2 - 1]);
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
