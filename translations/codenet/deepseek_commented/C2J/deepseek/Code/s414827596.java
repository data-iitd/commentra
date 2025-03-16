public class LinearEquationSolver {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        while (scanner.hasNextInt()) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int c = scanner.nextInt();
            int d = scanner.nextInt();
            int e = scanner.nextInt();
            int f = scanner.nextInt();

            double x = (double)(c * e - f * b) / (a * e - d * b);
            double y = (double)(c * d - f * a) / (b * d - e * a);

            if (Math.abs(y) <= 0.0005) y = 0;
            if (Math.abs(x) <= 0.0005) x = 0;

            System.out.printf("%.3f %.3f\n", x, y);
        }
        scanner.close();
    }
}
