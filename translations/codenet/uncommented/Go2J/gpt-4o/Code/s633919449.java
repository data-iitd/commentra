import java.util.*;

public class Main {
    static final int INITIAL_BUF_SIZE = 10000;
    static final int MAX_BUF_SIZE = 1000000;
    static final int MOD = (int) (1e9 + 7);
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = getInt();

        switch (N % 10) {
            case 2:
            case 4:
            case 5:
            case 7:
            case 9:
                System.out.println("hon");
                break;
            case 0:
            case 1:
            case 6:
            case 8:
                System.out.println("pon");
                break;
            case 3:
                System.out.println("bon");
                break;
        }
    }

    static int getInt() {
        return sc.nextInt();
    }

    static int[] getIntArray(int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = getInt();
        }
        return array;
    }

    static String getString() {
        return sc.next();
    }

    static String[] getStringArray(int n) {
        String[] array = new String[n];
        for (int i = 0; i < n; i++) {
            array[i] = getString();
        }
        return array;
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

    static boolean contains(int[] s, int e) {
        for (int v : s) {
            if (e == v) {
                return true;
            }
        }
        return false;
    }

    static int[] makeRange(int min, int max) {
        int[] a = new int[max - min + 1];
        for (int i = 0; i < a.length; i++) {
            a[i] = min + i;
        }
        return a;
    }

    static List<List<Integer>> powerset2(int[] nums) {
        int length = (int) Math.pow(2, nums.length);
        List<List<Integer>> result = new ArrayList<>(length);

        result.add(new ArrayList<>());

        for (int n : nums) {
            int max = result.size();
            for (int i = 0; i < max; i++) {
                List<Integer> newSubset = new ArrayList<>(result.get(i));
                newSubset.add(n);
                result.add(newSubset);
            }
        }

        return result;
    }

    static int calcGcd(int x, int y) {
        if (y == 0) {
            return x;
        } else if (x >= y) {
            return calcGcd(y, x % y);
        } else {
            return calcGcd(x, y % x);
        }
    }

    static List<Integer> getDivisor(int n) {
        Set<Integer> divisor = new HashSet<>();
        divisor.add(1);
        if (n != 1) {
            divisor.add(n);
        }

        int sqrt = (int) Math.sqrt(n);
        for (int i = 2; i <= sqrt; i++) {
            if (n % i == 0) {
                divisor.add(i);
                divisor.add(n / i);
            }
        }

        return new ArrayList<>(divisor);
    }

    static class IntHeap {
        private final PriorityQueue<Integer> heap;

        public IntHeap() {
            this.heap = new PriorityQueue<>(Collections.reverseOrder());
        }

        public void push(int x) {
            heap.offer(x);
        }

        public int pop() {
            return heap.poll();
        }

        public int size() {
            return heap.size();
        }
    }

    static IntHeap initHeap() {
        return new IntHeap();
    }

    static int factMod(int n) {
        int value = 1;
        for (; n > 1; n--) {
            value = calcMod(value * n);
        }
        return value;
    }

    static int combinationMod(int n, int k) {
        int factN = factMod(n);
        int factK = factMod(k);
        int factNK = factMod(n - k);
        int factKR = powMod(factK, MOD - 2);
        int factNKR = powMod(factNK, MOD - 2);
        return calcMod(factN * calcMod(factKR * factNKR));
    }

    static List<Integer> primeFactors(int n) {
        List<Integer> factors = new ArrayList<>();
        int i = 2;
        while (i * i <= n) {
            if (n % i == 0) {
                factors.add(i);
                n /= i;
            } else {
                i++;
            }
        }
        if (n > 1) {
            factors.add(n);
        }
        return factors;
    }
}
// <END-OF-CODE>
