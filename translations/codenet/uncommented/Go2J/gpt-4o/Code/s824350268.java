import java.util.*;

public class Main {
    static final int INITIAL_BUF_SIZE = 10000;
    static final int MAX_BUF_SIZE = 1000000;
    static final int MOD = (int) (1e9 + 7);
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = getInt();
        int sqrtN = (int) Math.sqrt(N);

        int min = N;
        for (int i = 1; i <= sqrtN; i++) {
            if (N % i != 0) {
                continue;
            }

            int num = i + (N / i) - 2;
            if (num < min) {
                min = num;
            }
        }

        System.out.println(min);
    }

    static int getInt() {
        return sc.nextInt();
    }

    static String getString() {
        return sc.next();
    }

    static int abs(int a) {
        return Math.abs(a);
    }

    static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    static int powMod(int n, int p) {
        if (p == 0) {
            return 1;
        } else if (p % 2 == 0) {
            int t = powMod(n, p / 2);
            return calcMod(t * t);
        } else {
            return calcMod(n * powMod(n, p - 1));
        }
    }

    static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true;
            }
        }
        return false;
    }

    static void printIntArray(int[] array) {
        System.out.println(Arrays.toString(array).substring(1, Arrays.toString(array).length() - 1));
    }

    static int calcMod(int x) {
        return x % MOD;
    }

    static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }

        int sqrtN = (int) Math.sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
}
// <END-OF-CODE>
