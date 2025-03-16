import java.util.Scanner;

public class CircleCalculations {
    public static void main(String[] args) {
        double r;
        double s, l;
        double p = 3.141592653589;
        
        Scanner scanner = new Scanner(System.in);
        r = scanner.nextDouble();
        
        s = r * r * p;
        l = 2 * p * r;
        
        System.out.printf("%f %f%n", s, l);
        
        scanner.close();
    }
}

// <END-OF-CODE>
