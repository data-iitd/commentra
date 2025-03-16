
import java.util.Scanner;
import java.util.TreeMap;

/*
     * Calculate definite integrals by using Composite Simpson's rule.
     * Wiki: https://en.wikipedia.org/wiki/Simpson%27s_rule#Composite_Simpson's_rule
     * Given f a function and an even number N of intervals that divide the integration interval
     * e.g. [a, b], we calculate the step h = (b-a)/N and create a table that contains all the x
     * points of the real axis xi = x0 + i*h and the value f(xi) that corresponds to these xi.
     *
     * To evaluate the integral i use the formula below:
     * I = h/3 * {f(x0) + 4*f(x1) + 2*f(x2) + 4*f(x3) + ... + 2*f(xN-2) + 4*f(xN-1) + f(xN)}
     *
     */
public class SimpsonIntegration {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        // Ensure n is even
        if (n % 2 != 0) {
            System.out.println("n must be an even number for Simpson's method. Exiting.");
            return;
        }

        double a = scanner.nextDouble();

        double b = scanner.nextDouble();

        SimpsonIntegration integration = new SimpsonIntegration();

        // Calculate step h and evaluate the integral
        double h = (b - a) / n;
        double integralEvaluation = integration.simpsonsMethod(n, h, a);
        System.out.println("The integral is equal to: " + integralEvaluation);
    }

    /*
     * @param N: Number of intervals (must be even number N=2*k)
     * @param h: Step h = (b-a)/N
     * @param a: Starting point of the interval
     * @param b: Ending point of the interval
     *
     * The interpolation points xi = x0 + i*h are stored the treeMap data
     *
     * @return result of the integral evaluation
     */
    public double simpsonsMethod(int n, double h, double a) {
        TreeMap<Integer, Double> data = new TreeMap<>(); // Key: i, Value: f(xi)
        double temp;
        double xi = a; // Initialize xi = x0

        // Create the table of xi and yi points
        for (int i = 0; i <= n; i++) {
            temp = f(xi); // Get the value of the function at xi
            data.put(i, temp);
            xi += h; // Increment xi to the next point
        }

        // Apply Simpson's rule formula
        double integralEvaluation = 0;
        for (int i = 0; i < data.size(); i++) {
            if (i == 0 || i == data.size() - 1) {
                integralEvaluation += data.get(i);
            } else if (i % 2 != 0) {
                integralEvaluation += 4 * data.get(i);
            } else {
                integralEvaluation += 2 * data.get(i);
            }
        }

        // Multiply by h/3
        integralEvaluation = h / 3 * integralEvaluation;

        // Return the result
        return integralEvaluation;
    }

    // Sample function f
    // Function f(x) = e^(-x) * (4 - x^2)
    public double f(double x) {
        return Math.exp(-x) * (4 - Math.pow(x, 2));
    }
}
