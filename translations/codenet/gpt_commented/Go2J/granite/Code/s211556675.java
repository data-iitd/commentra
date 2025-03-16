
import java.util.*;

public class s211556675{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();

        int ma = Math.max(A, Math.max(B, C));
        int rest = A + B + C - ma - ma;

        for (int i = 1; i <= K; i++) {
            ma *= 2;
        }

        System.out.println(ma + rest);
    }
}
