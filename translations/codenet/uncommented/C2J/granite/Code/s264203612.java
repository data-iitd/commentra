
import java.util.Scanner;

public class s264203612{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double r = sc.nextDouble();
        double s = Math.PI * r * r;
        double l = 2 * Math.PI * r;
        System.out.printf("%f %f\n", s, l);
    }
}
//END-OF-CODE