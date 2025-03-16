
public class Main {
    public static void main(String[] args) {
        double r;
        double s,l;
        double p = 3.141592653589;
        Scanner sc = new Scanner(System.in);
        r = sc.nextDouble();
        
        s = r*r*p;
        l = 2*p*r;
        
        System.out.println(s + " " + l);
    }
}

