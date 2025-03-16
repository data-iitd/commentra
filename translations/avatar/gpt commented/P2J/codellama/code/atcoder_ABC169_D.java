
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }
        List<Integer> fac = new ArrayList<>();
        int x = n;
        while (x % 2 == 0) {
            fac.add(2);
            x /= 2;
        }
        for (int i = 3; i * i <= x; i += 2) {
            while (x % i == 0) {
                fac.add(i);
                x /= i;
            }
        }
        if (x > 1) {
            fac.add(x);
        }
        int ans = 0;
        for (int i = 0; i < fac.size(); i++) {
            int p = fac.get(i);
            int e = 1;
            for (int j = i + 1; j < fac.size(); j++) {
                if (fac.get(j) == p) {
                    e++;
                }
            }
            for (int j = 1; j <= e; j++) {
                ans += j;
            }
        }
        System.out.println(ans);
    }
}

