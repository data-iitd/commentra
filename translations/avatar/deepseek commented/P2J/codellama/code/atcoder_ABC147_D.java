
import java.util.Scanner;
import java.util.stream.IntStream;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        long[] A = IntStream.range(0, N).mapToLong(i -> scanner.nextLong()).toArray();
        long result = 0;
        for (int b = 0; b < 60; b++) {
            long bs = IntStream.range(0, N).mapToLong(i -> (A[i] >> b) & 1).sum();
            result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
        }
        System.out.println(result);
    }
}

