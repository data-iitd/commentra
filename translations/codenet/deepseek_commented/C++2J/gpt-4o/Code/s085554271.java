import java.util.*;
import java.io.*;

public class Main {
    private static final long MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        long k = Long.parseLong(st.nextToken());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());

        for (long i = a; i <= b; i++) {
            if (i % k == 0) {
                System.out.println("OK");
                return;
            }
        }
        System.out.println("NG");
    }

    // Additional methods can be added here if needed
    // For example, methods for gcd, lcm, factorial, etc.
    
    // Example of a method to calculate gcd
    public static long gcd(long a, long b) {
        return b != 0 ? gcd(b, a % b) : a;
    }

    // Example of a method to calculate lcm
    public static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    // Example of a method to check if a number is prime
    public static boolean isPrime(int num) {
        if (num < 2) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;

        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    // Example of a method to calculate factorial
    public static long fact(int num) {
        if (num == 0) return 1;
        return num * fact(num - 1);
    }

    // Example of a method to calculate combinations
    public static long combination_mod(long n, long r, long mod) {
        if (r > n - r) r = n - r;
        if (r == 0) return 1;
        long a = 1;
        for (long i = 0; i < r; i++) {
            a = a * ((n - i) % mod) % mod;
        }
        long b = mod_pow(fact((int) r), mod - 2, mod);
        return (a % mod) * (b % mod) % mod;
    }

    // Example of a method for modular exponentiation
    public static long mod_pow(long x, long n, long mod) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) res = (res * x) % mod;
            x = (x * x) % mod;
            n >>= 1;
        }
        return res;
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

