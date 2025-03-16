import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if (n == 1) {
            System.out.println(0);
            return;
        }
        int ans = 0;
        Map<Integer, Integer> fac = new HashMap<>();
        for (int i = 2; i * i <= n; i++) {
            int x = n;
            while (x % i == 0) {
                x /= i;
                ans++;
            }
            if (x!= 1) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}

