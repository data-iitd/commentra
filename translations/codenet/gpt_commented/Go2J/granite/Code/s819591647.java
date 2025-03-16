
// problem_b.java

import java.io.*;
import java.util.*;

public class s819591647{
    // Define a constant for modulus operation
    private static final int MOD = 100000007;

    public static void main(String[] args) throws IOException {
        // Initialize scanner and writer for input and output
        Scanner sc = new Scanner(System.in);
        PrintWriter wr = new PrintWriter(System.out);

        // -----------------------------------------

        // Define a function to read a single integer from input
        int getInt() {
            sc.nextInt();
            return sc.nextInt();
        }

        // Define a function to read n integers from input and return them as a list
        List<Integer> getIntList(int n) {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(getInt());
            }
            return list;
        }

        // Define a function to read m lists of n integers from input and return them as a 2D list
        List<List<Integer>> getIntDoubleList(int m, int n) {
            List<List<Integer>> lists = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                List<Integer> list = getIntList(n);
                lists.add(list);
            }
            return lists;
        }

        // Define a function to read a single string from input
        String getString() {
            sc.next();
            return sc.next();
        }

        // Define a function to read n strings from input and return them as a list
        List<String> getStringList(int n) {
            List<String> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(getString());
            }
            return list;
        }

        // Define a function to read m lists of n strings from input and return them as a 2D list
        List<List<String>> getStringDoubleList(int m, int n) {
            List<List<String>> lists = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                List<String> list = getStringList(n);
                lists.add(list);
            }
            return lists;
        }

        // -----------------------------------------

        // Define a function to sort a list of integers in ascending order
        List<Integer> sortIntList(List<Integer> list) {
            Collections.sort(list);
            return list;
        }

        // Define a function to sort a list of integers in descending order
        List<Integer> sortIntReverseList(List<Integer> list) {
            Collections.sort(list, Collections.reverseOrder());
            return list;
        }

        // -----------------------------------------

        // Define a function to compute the absolute value of an integer
        int numAbs(int x) {
            return Math.abs(x);
        }

        // Define a function to compute a^n % m using modular exponentiation
        int numModPow(int a, int n, int m) {
            int result = 1;
            for (int i = 0; i < n; i++) {
                if (n % 2 == 1) {
                    result = (result * a) % m;
                }
                a = (a * a) % m;
                n /= 2;
            }
            return result;
        }

        // Define a function to compute the greatest common divisor of a and b
        int numGcd(int a, int b) {
            if (b == 0) {
                return a;
            }
            return numGcd(b, a % b);
        }

        // Define a function to compute the least common multiple of a and b
        int numLcm(int a, int b) {
            return a * b / numGcd(a, b);
        }

        // Define a function to compute the modular inverse of a under modulo p
        int numModInv(int a, int p) {
            if (a == 1) {
                return 1;
            }
            return p - numModInv(p % a, p) * (p / a) % p;
        }

        // Define a function to compute factorials modulo MOD up to n
        int[] numModFrac(int n) {
            int[] frac = new int[n + 1];
            frac[0] = 1;
            for (int i = 1; i <= n; i++) {
                frac[i] = i * frac[i - 1] % MOD;
            }
            return frac;
        }

        // Define a function to compute nCr % MOD using precomputed factorials
        int numModConb(int n, int r) {
            int[] frac = numModFrac(n);
            return (frac[n] * numModInv(frac[n - r], MOD) % MOD) * numModInv(frac[r], MOD) % MOD;
        }

        // -----------------------------------------

        // Define a function to solve the problem
        void solve() {
            // Read n and m from input
            int n = getInt();
            int m = getInt();
            // Read n integers into a list
            List<Integer> a = getIntList(n);

            // Calculate the sum of all elements in a
            int sum = 0;
            for (int v : a) {
                sum += v;
            }

            // Count how many elements in a meet the required rate
            int count = 0;
            for (int v : a) {
                double rate = (double) sum / (4 * m);
                if (v >= rate) {
                    count++;
                }
            }

            // Output "Yes" if count is greater than or equal to m, otherwise "No"
            if (count >= m) {
                wr.println("Yes");
            } else {
                wr.println("No");
            }
        }

        // -----------------------------------------

        // Call the solve function to execute the main logic
        solve();
        // Flush the writer to output results
        wr.flush();
    }
}

