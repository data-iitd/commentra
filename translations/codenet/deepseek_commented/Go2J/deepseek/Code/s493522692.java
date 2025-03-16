import java.util.Scanner;

public class Main {
    // Utility Functions

    // Reads the next input as a string
    static String nextStr() {
        return sc.nextLine();
    }

    // Reads the next input as an integer
    static int nextInt() {
        return Integer.parseInt(sc.nextLine());
    }

    // Returns the maximum of two integers
    static int maxInt(int a, int b) {
        return a > b ? a : b;
    }

    // Returns the minimum of two integers
    static int minInt(int a, int b) {
        return a > b ? b : a;
    }

    // Returns the absolute value of an integer
    static int absInt(int a) {
        return a >= 0 ? a : -a;
    }

    // Returns the absolute value of a float64
    static double absFloat64(double a) {
        return a >= 0 ? a : -a;
    }

    // Returns the maximum of two float64 values
    static double maxFloat64(double a, double b) {
        return a > b ? a : b;
    }

    // Returns the minimum of two float64 values
    static double minFloat64(double a, double b) {
        return a > b ? b : a;
    }

    // Converts a string to an integer
    static int str2Int(String s) {
        return Integer.parseInt(s);
    }

    // Reverses a string
    static String reverse(String s) {
        char[] chars = s.toCharArray();
        for (int i = 0, j = chars.length - 1; i < j; i++, j--) {
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
        }
        return new String(chars);
    }

    // Raises an integer to the power of another integer
    static int powInt(int p, int q) {
        return (int) Math.pow(p, q);
    }

    // Checks if a number is prime
    static boolean isPrime(int x) {
        if (x == 1) {
            return false;
        }
        if (x == 2) {
            return true;
        }
        if (x % 2 == 0) {
            return false;
        }

        boolean b = true;
        int rootx = (int) Math.sqrt(x);
        for (int i = 3; i <= rootx; i += 2) {
            if (x % i == 0) {
                b = false;
                break;
            }
        }
        return b;
    }

    // Returns the prime factors of a number
    static int[] PrimeFactors(int n) {
        // Get the number of 2s that divide n
        java.util.List<Integer> pfs = new java.util.ArrayList<>();
        while (n % 2 == 0) {
            pfs.add(2);
            n = n / 2;
        }

        // n must be odd at this point. so we can skip one element
        // (note i = i + 2)
        for (int i = 3; i * i <= n; i += 2) {
            // while i divides n, append i and divide n
            while (n % i == 0) {
                pfs.add(i);
                n = n / i;
            }
        }

        // This condition is to handle the case when n is a prime number
        // greater than 2
        if (n > 2) {
            pfs.add(n);
        }

        // Convert list to array
        int[] pfsArray = new int[pfs.size()];
        for (int i = 0; i < pfs.size(); i++) {
            pfsArray[i] = pfs.get(i);
        }
        return pfsArray;
    }

    // Returns the prime factors of a number as a map
    static java.util.Map<Integer, Integer> PrimeFactorsMap(int n) {
        java.util.Map<Integer, Integer> pfs = new java.util.HashMap<>();
        // Get the number of 2s that divide n
        while (n % 2 == 0) {
            pfs.put(2, pfs.getOrDefault(2, 0) + 1);
            n = n / 2;
        }

        // n must be odd at this point. so we can skip one element
        // (note i = i + 2)
        for (int i = 3; i * i <= n; i += 2) {
            // while i divides n, append i and divide n
            while (n % i == 0) {
                pfs.put(i, pfs.getOrDefault(i, 0) + 1);
                n = n / i;
            }
        }

        // This condition is to handle the case when n is a prime number
        // greater than 2
        if (n > 2) {
            pfs.put(n, pfs.getOrDefault(n, 0) + 1);
        }

        return pfs;
    }

    // Sums up a slice of integers
    static int sumInts(int[] x) {
        int total = 0;
        for (int v : x) {
            total += v;
        }
        return total;
    }

    // Computes the greatest common divisor of two integers
    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // Computes the least common multiple of two integers
    static int lcm(int x, int y) {
        return x * y / gcd(x, y);
    }

    // Constants and Variables

    static final int initialBufSize = 10000;
    static final int maxBufSize = 1000000;
    static final double mod = 1e9 + 7;

    static Scanner sc = new Scanner(System.in);

    // Main Function
    public static void main(String[] args) {
        sc.nextLine(); // Consume the first line to clear the buffer
        String[] inputs = sc.nextLine().split(" ");
        int N = Integer.parseInt(inputs[0]);
        int M = Integer.parseInt(inputs[1]);
        int tmp = Math.min(N, M / 2);
        int ans = tmp;
        N -= tmp;
        M -= tmp * 2;
        System.out.println(ans + M / 4);
    }
}
