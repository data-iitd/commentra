import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int d = scanner.nextInt();
        int x = scanner.nextInt();
        
        int result = main(N, d, x);
        System.out.println(result);
    }

    public static int main(int N, int d, int x) {
        int ret = 0;
        while (N > 0) {
            ret += d + (N - 0.5) * x;
            d = (int) (d + (d / N) + (5 * x) / (2 * N));
            x = (int) (x + 2 * x / N);
            N--;
        }
        return ret;
    }
}
