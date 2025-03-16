
import java.util.Arrays;
import java.util.Scanner;

public class s876981782{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        double[] values = new double[N];
        for (int i = 0; i < N; i++) {
            values[i] = scanner.nextDouble();
        }

        Arrays.sort(values);
        double generated = 0;
        for (int i = 0; i < N - 1; i++) {
            generated = (values[i] + values[i + 1]) / 2;
            values[i + 1] = generated;
        }

        System.out.println(generated);
    }
}
