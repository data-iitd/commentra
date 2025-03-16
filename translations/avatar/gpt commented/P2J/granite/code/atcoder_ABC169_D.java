
import java.io.*;
import java.util.*;

public class atcoder_ABC169_D{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println(0);
            return;
        }
        List<Integer> factors = new ArrayList<>();
        int num = n;
        for (int i = 2; i * i <= num; i++) {
            while (num % i == 0) {
                factors.add(i);
                num /= i;
            }
        }
        if (num > 1) {
            factors.add(num);
        }
        Map<Integer, Integer> factorCounts = new HashMap<>();
        for (int factor : factors) {
            factorCounts.put(factor, factorCounts.getOrDefault(factor, 0) + 1);
        }
        int ans = 0;
        for (int count : factorCounts.values()) {
            int x = count;
            for (int i = 1; i <= count; i++) {
                if (x >= i) {
                    x -= i;
                    ans++;
                } else {
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "