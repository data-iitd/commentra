
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        double r = sc.nextDouble();
        double s,l;
        double p = 3.141592653589;
        s = r*r*p;
        l = 2*p*r;
        System.out.printf("%f %f\n",s,l);
    }
}
