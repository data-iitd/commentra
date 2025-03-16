import java.util.*;
import java.io.*;

public class Main {
    // Constants for maximum limits
    static final int MAX_N = 1000000;
    static final long MAX_N_Int = 1000000000000L;
    static final long MOD = 1000000007;

    // Function to print a list with a specified separator
    static <T> void printList(List<T> list, String separator) {
        if (!list.isEmpty()) {
            for (int i = 0; i < list.size() - 1; i++) {
                System.out.print(list.get(i) + separator);
            }
            System.out.println(list.get(list.size() - 1));
        }
    }

    // Function to check if a number is prime
    static boolean isPrime(int num) {
        if (num < 2) return false; // Numbers less than 2 are not prime
        else if (num == 2) return true; // 2 is prime
        else if (num % 2 == 0) return false; // Exclude even numbers

        double sqrtNum = Math.sqrt(num); // Calculate square root for optimization
        for (int i = 3; i <= sqrtNum; i += 2) { // Check for factors from 3 to sqrt(num)
            if (num % i == 0) {
                return false; // Not a prime number
            }
        }

        return true; // Number is prime
    }

    // Function to calculate the greatest common divisor (GCD)
    static long gcd(long a, long b) {
        return b != 0 ? gcd(b, a % b) : a; // Recursive GCD calculation
    }

    // Function to calculate the least common multiple (LCM)
    static long lcm(long a, long b) {
        return a / gcd(a, b) * b; // LCM using GCD
    }

    // Function to find the maximum of three integers
    static int max(int a, int b, int c) {
        return Math.max(Math.max(a, b), c); // Return the maximum value
    }

    // Function to find the minimum of three integers
    static int min(int a, int b, int c) {
        return Math.min(Math.min(a, b), c); // Return the minimum value
    }

    // Function to check if a double is an integer
    static boolean isInteger(double num) {
        return Math.floor(num) == num; // Check if the number is an integer
    }

    // Recursive function to calculate factorial
    static long factorial(int num) {
        if (num == 0)
            return 1; // Base case for factorial
        else
            return num * factorial(num - 1); // Recursive case
    }

    // Function to count the number of divisors of n
    static long countDivisors(int n) {
        int cnt = 0; // Counter for divisors
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++; // Count the divisor
                if (i * i != n) cnt++; // Count the complementary divisor if it's different
            }
        }
        return cnt; // Return the count of divisors
    }

    // Function to calculate factorial modulo a given number
    static long factorialMod(long n, long mod) {
        long f = 1;
        for (long i = 2; i <= n; i++) f = f * (i % MOD) % MOD; // Calculate factorial with modulo
        return f; // Return the result
    }

    // Function to perform modular exponentiation
    static long modPow(long x, long n, long mod) {
        long res = 1; // Initialize result
        while (n > 0) {
            if ((n & 1) == 1) res = (res * x) % mod; // If n is odd, multiply x with result
            x = (x * x) % mod; // Square x
            n >>= 1; // Divide n by 2
        }
        return res; // Return the result
    }

    // Function to calculate combinations nCr modulo a given number
    static long combinationMod(long n, long r, long mod) {
        if (r > n - r) r = n - r; // Use symmetry property of combinations
        if (r == 0) return 1; // Base case for combinations
        long a = 1;
        for (long i = 0; i < r; i++) a = a * ((n - i) % mod) % mod; // Calculate numerator
        long b = modPow(factorialMod(r, mod), mod - 2, mod); // Calculate denominator using Fermat's Little Theorem
        return (a % mod) * (b % mod) % mod; // Return the result
    }

    // Function to check if a string is a palindrome
    static boolean isPalindrome(String s) {
        String t = s;
        String reversed = new StringBuilder(s).reverse().toString(); // Reverse the string
        return s.equals(reversed); // Check if the original string is equal to the reversed string
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long k = scanner.nextLong();
        long a = scanner.nextLong();
        long b = scanner.nextLong();

        // Check for multiples of k in the range [a, b]
        for (long i = a; i <= b; i++) {
            if (i % k == 0) {
                System.out.println("OK"); // Output OK if a multiple is found
                return; // Exit the program
            }
        }
        System.out.println("NG"); // Output NG if no multiples are found
    }
}

/*
テレビも無ェ ラジオも無ェ
自動車もそれほど走って無ェ
ピアノも無ェ バーも無ェ
巡査 毎日ぐーるぐる
朝起ぎで 牛連れで
二時間ちょっとの散歩道
電話も無ェ 瓦斯も無ェ
バスは一日一度来る
俺らこんな村いやだ 俺らこんな村いやだ
東京へ出るだ 東京へ出だなら
銭コァ貯めで 東京でベコ(牛)飼うだ
*/

