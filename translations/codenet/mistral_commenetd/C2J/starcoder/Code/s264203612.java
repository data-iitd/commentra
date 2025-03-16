
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double r = sc.nextDouble();
        double s = r*r*3.141592653589;
        double l = 2*3.141592653589*r;
        System.out.println(s+" "+l);
    }
}

