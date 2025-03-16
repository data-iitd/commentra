import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();

        int max = Math.max(A, Math.max(B, C));
        int rest = 0;
        if (max == A) {
            rest = B + C;
        } else if (max == B) {
            rest = A + C;
        } else {
            rest = A + B;
        }

        for (int i = 1; i <= K; i++) {
            max *= 2;
        }

        System.out.println(max + rest);
    }
}
