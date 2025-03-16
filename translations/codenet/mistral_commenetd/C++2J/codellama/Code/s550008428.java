
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int s = sc.nextInt();
        Set<Integer> a = new HashSet<>();
        a.add(s);
        int d = 2;

        while(true) {
            if(s%2==0) {
                int x = s/2;
                if(a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            } else {
                int x = 3*s + 1;
                if(a.contains(x)) {
                    System.out.println(d);
                    return;
                }
                a.add(x);
            }
            s = x;
            d++;
        }

        System.out.println(d);
    }
}

