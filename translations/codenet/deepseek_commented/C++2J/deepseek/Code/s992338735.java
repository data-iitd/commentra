public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            int N = scanner.nextInt();
            if (N > 0) {
                int M = -1, m = 1001, addup = 0, S;
                for (int i = 0; i < N; i++) {
                    S = scanner.nextInt();
                    addup += S;
                    if (S > M) M = S;
                    if (S < m) m = S;
                }
                System.out.println((addup - M - m) / (N - 2));
            }
        }
    }
}
