
import java.util.Scanner;
import java.util.stream.IntStream;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = IntStream.range(0, N).map(i -> scanner.nextInt()).toArray();
        int result = 0;
        for (int b = 0; b < 60; b++) {
            int bs = (int) IntStream.range(0, N).filter(i -> (A[i] & (1 << b)) != 0).count();
            result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
        }
        System.out.println(result);
    }
}

