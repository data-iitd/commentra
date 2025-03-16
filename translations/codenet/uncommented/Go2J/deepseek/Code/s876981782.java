public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        double[] values = new double[N];
        for (int i = 0; i < N; i++) {
            values[i] = scanner.nextDouble();
        }

        java.util.Arrays.sort(values);
        double generated = 0;
        for (int i = 0; i < N - 1; i++) {
            generated = (values[i] + values[i + 1]) / 2;
            values[i + 1] = generated;
        }

        System.out.println(generated);
    }
}
