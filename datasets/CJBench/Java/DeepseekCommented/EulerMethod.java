import java.util.ArrayList;
import java.util.Scanner;
import java.util.function.BiFunction;
public final class Main {
    private Main() {
    }
    // Main entry point of the program
    public static void main(String[] args) {
        // Initialize scanner to read input
        Scanner scanner = new Scanner(System.in);
        // Read initial and final values of x, step size, initial value of y, and equation choice
        double xStart = scanner.nextDouble();
        double xEnd = scanner.nextDouble();
        double stepSize = scanner.nextDouble();
        double yStart = scanner.nextDouble();
        int equationChoice = scanner.nextInt();
        // Initialize the differential equation based on user choice
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
        // Compute the points using Euler's method
        ArrayList<double[]> points = eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation);
        // Print the results
        System.out.println("Results:");
        for (double[] point : points) {
            System.out.printf("x: %.6f; y: %.6f%n", point[0], point[1]);
        }
    }
    // Computes the next y value using Euler's method
    public static double eulerStep(double xCurrent, double stepSize, double yCurrent, BiFunction<Double, Double, Double> differentialEquation) {
        if (stepSize <= 0) {
            throw new IllegalArgumentException("stepSize should be greater than zero");
        }
        return yCurrent + stepSize * differentialEquation.apply(xCurrent, yCurrent);
    }
    // Computes all points using Euler's method from xStart to xEnd
    public static ArrayList<double[]> eulerFull(double xStart, double xEnd, double stepSize, double yStart, BiFunction<Double, Double, Double> differentialEquation) {
        if (xStart >= xEnd) {
            throw new IllegalArgumentException("xEnd should be greater than xStart");
        }
        if (stepSize <= 0) {
            throw new IllegalArgumentException("stepSize should be greater than zero");
        }
        // Initialize the list to store points
        ArrayList<double[]> points = new ArrayList<>();
        // Add the initial point
        points.add(new double[]{xStart, yStart});
        double yCurrent = yStart;
        double xCurrent = xStart;
        // Iterate through the range to compute points
        while (xCurrent < xEnd) {
            yCurrent = eulerStep(xCurrent, stepSize, yCurrent, differentialEquation);
            xCurrent += stepSize;
            points.add(new double[]{xCurrent, yCurrent});
        }
        return points;
    }
}
