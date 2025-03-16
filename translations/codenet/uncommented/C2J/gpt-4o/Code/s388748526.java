import java.util.Scanner;

public class CircleCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double r = scanner.nextDouble();
        System.out.printf("%f %f%n", r * r * Math.PI, 2 * Math.PI * r);
        scanner.close();
    }
}

// <END-OF-CODE>
