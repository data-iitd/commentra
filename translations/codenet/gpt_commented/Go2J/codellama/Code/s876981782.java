
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        double[] values = new double[N];
        for (int i = 0; i < N; i++) {
            values[i] = sc.nextDouble();
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

