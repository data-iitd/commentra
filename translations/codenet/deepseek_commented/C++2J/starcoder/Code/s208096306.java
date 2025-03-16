import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int ans = in.nextInt();
        for (int i = 1; i < n; ++i) {
            int a = in.nextInt();
            ans = gcd(ans, a);
        }
        System.out.println(ans);
    }

    public static int gcd(int a, int b) {
        if (a < b) swap(a, b);
        int r;
        while ((r = a%b) > 0) {
            a = b;
            b = r;
        }
        return b;
    }
}

