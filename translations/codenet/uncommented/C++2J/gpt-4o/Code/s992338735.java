import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N, S;

        while (scanner.hasNext() && (N = scanner.nextInt()) > 0) {
            int M = -1, m = 1001, addup = 0;

            for (int i = 0; i < N; i++) {
                S = scanner.nextInt();
                addup += S;
                if (S > M) M = S;
                if (S < m) m = S;
            }
            System.out.println((addup - M - m) / (N - 2));
        }
        scanner.close();
    }
}
// <END-OF-CODE>
