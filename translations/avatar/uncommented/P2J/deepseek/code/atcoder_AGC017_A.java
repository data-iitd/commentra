import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int P = scanner.nextInt();

        String[] input = scanner.nextLine().split(" ");
        int[] lis = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            lis[i] = Integer.parseInt(input[i]);
        }

        List<Integer> ls = new ArrayList<>();
        for (int a : lis) {
            ls.add(a % 2);
        }

        int one = 0;
        int zero = 0;
        for (int l : ls) {
            if (l == 1) {
                one++;
            } else {
                zero++;
            }
        }

        double pattern_a = 0;
        double pattern_b = 0;
        for (int j = 0; j <= zero; j++) {
            pattern_b += combi(zero, j);
        }

        int time = 0;
        while (time <= one) {
            if (time % 2 == P) {
                pattern_a += combi(one, time);
            }
            time++;
        }

        System.out.println((int) (pattern_a * pattern_b));
    }

    public static double combi(int N, int K) {
        double a = 1;
        for (int i = 0; i < K; i++) {
            a *= N - i;
        }
        for (int j = 0; j < K; j++) {
            a /= j + 1;
        }
        return a;
    }
}
