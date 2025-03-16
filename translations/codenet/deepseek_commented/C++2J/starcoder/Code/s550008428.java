import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s, x, d=2;
        s = sc.nextInt();
        Set<Integer> a = new HashSet<Integer>();
        a.add(s);
        while(true) {
            if(s%2==0) {
                x = s/2;
                if(a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            } else {
                x = 3*s + 1;
                if(a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            }
            s = x;
            d++;
        }
    }
}
