
// Importing necessary Java packages
import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.BigInteger;

// Defining the Main class with a main method
public class Main {
    // Initializing input and output streams and creating InputReader and PrintWriter objects
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        // Calling the solve method with InputReader and PrintWriter objects as arguments
        solve(in, out);

        // Closing the PrintWriter
        out.close();
    }

    // Declaring static variables L, R, top, bottom and an integer variable 'ans' (commented out)
    static int L, R, top, bottom;
    // static int ans;

    // Define a static method 'solve' that takes InputReader and PrintWriter as arguments
    public static void solve(InputReader sc, PrintWriter pw) {
        // Initializing a variable 't' with value 1
        int t = 1;

        // Using a while loop to process the test cases
        while (t-->0) {
            // Reading the length 'n' and breadth 'm' of the rectangle from the InputReader
            long n = sc.nextLong();
            long m = sc.nextLong();

            // Checking if the length and breadth are equal to 0
            if (n == 0) {
                // If yes, then print 0 as the answer and continue to the next test case
                pw.println(0);
                continue;
            }

            // Checking if the length and breadth are equal
            if (n == m) {
                // If yes, then print 0 as the answer and continue to the next test case
                pw.println(0);
                continue;
            }

            // Checking if the length is greater than the breadth
            if (n > m) {
                // If yes, then calculate the smaller value between 'm' and 'n-m' and print it as the answer
                n = m + n % m;
                n -= m;
                pw.println(Math.min(m - n, n));
                continue;
            }

            // If the length is smaller than the breadth, then calculate the smaller value between 'm-n' and 'n' and print it as the answer
            pw.println(Math.min(m - n, n));
        }
    }

    // Define a static method 'swap' that takes a character array, two indices 'i' and 'j' as arguments and swaps the elements at those indices
    public static void swap(char []chrr, int i, int j) {
        // Declaring a variable 'temp' of type char
        char temp;

        // Swapping the elements at indices 'i' and 'j' in the character array 'chrr'
        temp = chrr[i];
        chrr[i] = chrr[j];
        chrr[j] = temp;
    }

    // Define a static method 'num' that takes an integer 'n' as an argument and returns the number of set bits in its binary representation
    public static int num(int n) {
        int a = 0;

        // Using a while loop to count the number of set bits in the binary representation of 'n'
        while (n > 0) {
            a += (n & 1);
            n >>= 1;
        }

        // Returning the count of set bits
        return a;
    }

    // Define a static class 'Pair' with three instance variables 'u', 'v', and 'i' and a constructor that initializes these variables
    static class Pair {
        int u, v, i, val;

        Pair(int a, int b, int i) {
            this.u = a;
            this.v = b;
            this.i = i;
        }
    }

    // Define a static method 'isPrime' that takes an integer 'n' as an argument and returns a boolean value indicating whether it is a prime number or not
    static boolean isPrime(int n) {
        if (n <= 1) {
            // If 'n' is less than or equal to 1, then it is not a prime number
            return false;
        }

        if (n <= 3) {
            // If 'n' is less than or equal to 3, then it is a prime number
            return true;
        }

        if (n % 2 == 0 || n % 3 == 0) {
            // If 'n' is even or a multiple of 3, then it is not a prime number
            return false;
        }

        // Using a for loop to check divisibility of 'n' with numbers of the form 6k±1
        for (int i = 5; i * i <= n; i = i + 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                // If 'n' is divisible by 'i' or (i+2), then it is not a prime number
                return false;
            }
        }

        // If 'n' is not divisible by any number in the range [2, sqrt(n)], then it is a prime number
        return true;
    }

    // Define a static method 'gcd' that takes two long integers 'a' and 'b' as arguments and returns their greatest common divisor
    static long gcd(long a, long b) {
        if (b == 0) {
            // If 'b' is 0, then 'a' is the greatest common divisor
            return a;
        }

        // Using a recursive call to find the greatest common divisor of 'b' and the remainder of 'a' divided by 'b'
        return a > b ? gcd(b, a % b) : gcd(a, b % a);
    }

    // Define a static method 'fast_pow' that takes three long integers 'base', 'n', and 'M' as arguments and returns base raised to the power 'n' modulo 'M'
    static long fast_pow(long base, long n, long M) {
        if (n == 0) {
            // If 'n' is 0, then the answer is 1
            return 1;
        }

        if (n == 1) {
            // If 'n' is 1, then the answer is 'base' modulo 'M'
            return base;
        }

        // Calculating half of 'n' and recursively finding the value of base raised to the power half of 'n' modulo 'M'
        long halfn = fast_pow(base, n / 2, M);

        // If 'n' is even, then the answer is the square of half of 'n' modulo 'M'
        if (n % 2 == 0) {
            return (halfn * halfn) % M;
        }

        // If 'n' is odd, then the answer is the product of base raised to the power half of 'n' modulo 'M' and base itself modulo 'M'
        else {
            return ((halfn * halfn) % M * base) % M;
        }
    }

    // Define a static method 'modInverse' that takes two long integers 'n' and 'M' as arguments and returns the modular multiplicative inverse of 'n' modulo 'M'
    static long modInverse(long n, long M) {
        // Using the fast_pow method to find the value of 'n' raised to the power 'M-2' modulo 'M'
        return fast_pow(n, M - 2, M);
    }

    // Define static methods 'feedArr' for initializing different types of arrays with input from the InputReader
    public static void feedArr(long []arr, InputReader sc) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextLong();
        }
    }

    public static void feedArr(double []arr, InputReader sc) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextDouble();
        }
    }

    public static void feedArr(int []arr, InputReader sc) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
    }

    public static void feedArr(String []arr, InputReader sc) {
        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.next();
        }
    }

    // Define static methods 'printArr' for printing different types of arrays
    public static String printArr(int []arr) {
        StringBuilder sbr = new StringBuilder();
        for (int i : arr) {
            sbr.append(i + " ");
        }
        return sbr.toString();
    }

    public static String printArr(long []arr) {
        StringBuilder sbr = new StringBuilder();
        for (long i : arr) {
            sbr.append(i + " ");
        }
        return sbr.toString();
    }

    public static String printArr(String []arr) {
        StringBuilder sbr = new StringBuilder();
        for (String i : arr) {
            sbr.append(i + " ");
        }
        return sbr.toString();
    }

    public static String printArr(double []arr) {
        StringBuilder sbr = new StringBuilder();
        for (double i : arr) {
            sbr.append(i + " ");
        }
        return sbr.toString();
    }
}
