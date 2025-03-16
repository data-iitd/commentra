
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

        List<Integer> primeFactors = new ArrayList<>();
        int num = n;
        for (int i = 2; i * i <= num; i++) {
            while (num % i == 0) {
                primeFactors.add(i);
                num /= i;
            }
        }
        if (num > 1) {
            primeFactors.add(num);
        }

        Map<Integer, Integer> factorCounts = new HashMap<>();
        for (int factor : primeFactors) {
            factorCounts.put(factor, factorCounts.getOrDefault(factor, 0) + 1);
        }

        int result = 0;
        for (int count : factorCounts.values()) {
            int x = count;
            for (int i = 1; i <= count; i++) {
                if (x >= i) {
                    x -= i;
                    result++;
                } else {
                    break;
                }
            }
        }

        System.out.println(result);
    }
}

Translate the above Java code to C++ and end with comment "