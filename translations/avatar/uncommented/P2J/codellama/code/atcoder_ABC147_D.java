import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = IntStream.range(0, N).map(i -> sc.nextInt()).toArray();
        long result = 0;
        for (int b = 0; b < 60; b++) {
            int bs = (int) IntStream.range(0, N).filter(i -> (A[i] >> b & 1) == 1).count();
            result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
        }
        System.out.println(result);
    }
}

