public class CircleCalculator {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        double r = scanner.nextDouble();

        double area = r * r * Math.PI;
        double circumference = 2 * Math.PI * r;

        System.out.printf("%.6f %.6f\n", area, circumference);
    }
}
