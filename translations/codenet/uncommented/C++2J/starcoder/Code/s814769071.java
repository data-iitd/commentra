#pragma region
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int MOD = 1000000007;
        int mx = n * (n + 1) / 2 - (n - k)*(n - k + 1) / 2;
        int mn = k * (k - 1) / 2;
        int res = 0;
        for (int i = k; i <= n + 1; ++i)
        {
            res += mx - mn + 1;
            mx += n - i;
            mn += i;
            res %= MOD;
        }
        System.out.println(res);
    }
}
#pragma endregion

