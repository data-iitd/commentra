import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());
        long[] A = new long[N];
        String[] input = scanner.nextLine().split(" ");
        
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(input[i]);
        }
        
        long result = 0;
        final int MOD = 1000000007;

        for (int b = 0; b < 60; b++) {
            long bs = 0;
            for (int i = 0; i < N; i++) {
                if ((A[i] >> b & 1) == 1) {
                    bs++;
                }
            }
            result = (result + bs * (N - bs) % MOD * (1L << b) % MOD) % MOD;
        }
        
        System.out.println(result);
        scanner.close();
    }
}
// <END-OF-CODE>
