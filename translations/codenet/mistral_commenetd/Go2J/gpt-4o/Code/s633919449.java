import java.util.*;
import java.io.*;

public class Main {
    // Constants for modulo value
    static final int MOD = (int) (1e9 + 7);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read an integer input
        int N = getInt(sc);

        // Determine the output based on the last digit of N
        switch (N % 10) {
            case 2: case 4: case 5: case 7: case 9:
                System.out.println("hon");
                break;
            case 0: case 1: case 6: case 8:
                System.out.println("pon");
                break;
            case 3:
                System.out.println("bon");
                break;
        }
    }

    // Function to read an integer from input
    static int getInt(Scanner sc) {
        return sc.nextInt();
    }

    // Function to read an array of integers from input
    static int[] getIntArray(Scanner sc, int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = getInt(sc);
        }
        return array;
    }

    // Function to read a string from input
    static String getString(Scanner sc) {
        return sc.next();
    }

    // Function to read an array of strings from input
    static String[] getStringArray(Scanner sc, int n) {
        String[] array = new String[n];
        for (int i = 0; i < n; i++) {
            array[i] = getString(sc);
        }
        return array;
    }

    // Function to calculate the absolute value of an integer
    static int abs(int a) {
        return Math.abs(a);
    }

    // Function to calculate p raised to the power of q
    static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    // Function to calculate n raised to the power of p modulo mod
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

    // Function to calculate x modulo mod
    static int calcMod(int x) {
        return x % MOD;
    }

    // Function to find the minimum value among a list of integers
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

    // Function to find the maximum value among a list of integers
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

    // Function to check if a number is prime
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

    // Function to calculate factorial modulo mod
    static int factMod(int n) {
        int value = 1;
        for (; n > 1; n--) {
            value = calcMod(value * n);
        }
        return value;
    }

    // Function to calculate combinations modulo mod
    static int combinationMod(int n, int k) {
        int factN = factMod(n);
        int factK = factMod(k);
        int factNK = factMod(n - k);
        int factKR = powMod(factK, MOD - 2);
        int factNKR = powMod(factNK, MOD - 2);
        return calcMod(factN * calcMod(factKR * factNKR));
    }

    // Function to find prime factors of a number
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
