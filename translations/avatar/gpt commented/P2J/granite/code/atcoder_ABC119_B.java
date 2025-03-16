
import java.util.Scanner;

public class atcoder_ABC119_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        double[] x = new double[N];
        for (int i = 0; i < N; i++) {
            String input = scanner.next();
            if (input.equals("JPY")) {
                x[i] = scanner.nextDouble() * 1.0;
            } else if (input.equals("BTC")) {
                x[i] = scanner.nextDouble() * 380000.0;
            }
        }
        double sum = 0;
        for (double value : x) {
            sum += value;
        }
        System.out.println(sum);
    }
}
