
import java.util.Scanner;
import java.util.TreeMap;
public class SimpsonIntegration {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        if (n % 2 != 0) {
            System.out.println("n must be an even number for Simpson's method. Exiting.");
            return;
        }
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        SimpsonIntegration integration = new SimpsonIntegration();
        double h = (b - a) / n;
        double integralEvaluation = integration.simpsonsMethod(n, h, a);
        System.out.println("The integral is equal to: " + integralEvaluation);
    }
    public double simpsonsMethod(int n, double h, double a) {
        TreeMap<Integer, Double> data = new TreeMap<>(); 
        double temp;
        double xi = a; 
        for (int i = 0; i <= n; i++) {
            temp = f(xi); 
            data.put(i, temp);
            xi += h; 
        }
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
        integralEvaluation = h / 3 * integralEvaluation;
        return integralEvaluation;
    }
    public double f(double x) {
        return Math.exp(-x) * (4 - Math.pow(x, 2));
    }
}
