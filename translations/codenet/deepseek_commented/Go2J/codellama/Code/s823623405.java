
package main;

import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); // Read the number of elements
        int[] as = new int[n];
        HashMap<Integer, Integer> ps = new HashMap<>();
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt(); // Read each element of the array

            HashMap<Integer, Integer> ns = primeFactorize(as[i]); // Prime factorize the current element
            for (int k : ns.keySet()) {
                ps.put(k, Math.max(ps.getOrDefault(k, 0), ns.get(k))); // Update the map with the prime factors and their powers
            }
        }

        int x = 1;
        for (int k : ps.keySet()) {
            for (int i = 1; i <= ps.get(k); i++) {
                x = mul(x, k); // Calculate the LCM by multiplying the prime factors with their powers
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = add(ans, div(x, as[i])); // Calculate the sum of modular inverses
        }
        System.out.println(ans); // Print the final answer
    }

    public static int max(int a, int b) {
        if (a > b) {
            return a;
        }
        return b;
    }

    public static HashMap<Integer, Integer> primeFactorize(int n) {
        HashMap<Integer, Integer> res = new HashMap<>();
        for (int i = 2; i*i <= n; i++) {
            while (n % i == 0) {
                n /= i;
                res.put(i, res.getOrDefault(i, 0) + 1);
            }
        }
        if (n != 1) {
            res.put(n, res.getOrDefault(n, 0) + 1);
        }
        return res;
    }

    public static int pow(int n, int k) {
        if (k == 0) {
            return 1;
        } else if (k % 2 == 1) {
            return pow(n, k-1) * n % mod;
        } else {
            int t = pow(n, k/2);
            return t * t % mod;
        }
    }

    public static int add(int a, int b) {
        return (a + b) % mod;
    }

    public static int sub(int a, int b) {
        return (a + mod - b) % mod;
    }

    public static int mul(int a, int b) {
        return a % mod * b % mod % mod;
    }

    public static int div(int a, int b) {
        return mul(a, pow(b, mod-2));
    }

    public static final int mod = 1000000007;
}

