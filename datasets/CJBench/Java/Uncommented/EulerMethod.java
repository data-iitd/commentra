import java.util.ArrayList;
import java.util.Scanner;
import java.util.function.BiFunction;
public final class EulerMethod {
    private EulerMethod() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double xStart = scanner.nextDouble();
        double xEnd = scanner.nextDouble();
        double stepSize = scanner.nextDouble();
        double yStart = scanner.nextDouble();
        int equationChoice = scanner.nextInt();
        BiFunction<Double, Double, Double> differentialEquation;
        switch (equationChoice) {
            case 1:
                differentialEquation = (x, y) -> x;
                break;
            case 2:
                differentialEquation = (x, y) -> y;
                break;
            case 3:
                differentialEquation = (x, y) -> x + y + x * y;
                break;
            default:
                throw new IllegalArgumentException("Invalid choice of differential equation");
        }
        ArrayList<double[]> points = eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation);
        System.out.println("Results:");
        for (double[] point : points) {
            System.out.printf("x: %.6f; y: %.6f%n", point[0], point[1]);
        }
    }
    public static double eulerStep(double xCurrent, double stepSize, double yCurrent, BiFunction<Double, Double, Double> differentialEquation) {
        if (stepSize <= 0) {
            throw new IllegalArgumentException("stepSize should be greater than zero");
        }
        return yCurrent + stepSize * differentialEquation.apply(xCurrent, yCurrent);
    }
    public static ArrayList<double[]> eulerFull(double xStart, double xEnd, double stepSize, double yStart, BiFunction<Double, Double, Double> differentialEquation) {
        if (xStart >= xEnd) {
            throw new IllegalArgumentException("xEnd should be greater than xStart");
        }
        if (stepSize <= 0) {
            throw new IllegalArgumentException("stepSize should be greater than zero");
        }
        ArrayList<double[]> points = new ArrayList<>();
        points.add(new double[]{xStart, yStart});
        double yCurrent = yStart;
        double xCurrent = xStart;
        while (xCurrent < xEnd) {
            yCurrent = eulerStep(xCurrent, stepSize, yCurrent, differentialEquation);
            xCurrent += stepSize;
            points.add(new double[]{xCurrent, yCurrent});
        }
        return points;
    }
}
