import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        int K = scanner.nextInt();

        int max = Math.max(A, Math.max(B, C));
        int rest = A + B + C - max;

        for (int i = 0; i < K; i++) {
            max *= 2;
        }

        System.out.println(max + rest);
    }
}
