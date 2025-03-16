
import java.util.Scanner;
import java.util.stream.IntStream;

public class atcoder_ABC118_C{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }
        int gcd = IntStream.of(A).reduce(0, (a, b) -> {
            while (b!= 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        });
        System.out.println(gcd);
    }
}
