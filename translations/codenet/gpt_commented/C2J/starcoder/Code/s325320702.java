
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long l = sc.nextLong();
        long r = sc.nextLong();
        long d = sc.nextLong();
        long ans = 0;
        for (long i = l; i <= r; i++) {
            if (i % d == 0) ans++;
        }
        System.out.println(ans);
    }
}

