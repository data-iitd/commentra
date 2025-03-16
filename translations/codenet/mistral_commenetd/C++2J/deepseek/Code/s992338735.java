import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextInt()) {
            int N = scanner.nextInt();
            if (N <= 0) break;

            int M = -1;
            int m = 1001;
            int addup = 0;

            for (int i = 0; i < N; i++) {
                int S = scanner.nextInt();
                addup += S;
                if (S > M) M = S;
                if (S < m) m = S;
            }

            System.out.println((addup - M - m) / (N - 2));
        }

        scanner.close();
    }
}
