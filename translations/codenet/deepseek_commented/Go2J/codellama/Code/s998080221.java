
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static final StringBuilder writer = new StringBuilder();

    private static int N, _;
    private static int[] A;
    private static int maxProfit;
    private static int maxCnt;
    private static int maxA;

    public static void main(String[] args) throws IOException {
        solve();
        System.out.println(writer);
    }

    private static void solve() throws IOException {
        N = nextInt();
        _ = nextInt();
        A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = nextInt();
        }
        maxProfit = 0;
        maxCnt = 0;
        maxA = A[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            int profit = Math.max(0, maxA - A[i]);
            if (maxProfit < profit) {
                maxProfit = profit;
                maxCnt = 1;
            } else if (maxProfit == profit) {
                maxCnt++;
            }
            maxA = Math.max(maxA, A[i]);
        }
        writer.append(maxCnt);
    }

    private static int nextInt() throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        return Integer.parseInt(tokenizer.nextToken());
    }

    private static int nextInt(int n) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(tokenizer.nextToken());
        }
        return A[n - 1];
    }

    private static int[] nextIntArray(int n) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(tokenizer.nextToken());
        }
        return A;
    }

    private static long nextLong() throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        return Long.parseLong(tokenizer.nextToken());
    }

    private static long nextLong(int n) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        long[] A = new long[n];
        for (int i = 0; i < n; i++) {
            A[i] = Long.parseLong(tokenizer.nextToken());
        }
        return A[n - 1];
    }

    private static long[] nextLongArray(int n) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        long[] A = new long[n];
        for (int i = 0; i < n; i++) {
            A[i] = Long.parseLong(tokenizer.nextToken());
        }
        return A;
    }

    private static double nextDouble() throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        return Double.parseDouble(tokenizer.nextToken());
    }

    private static double nextDouble(int n) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        double[] A = new double[n];
        for (int i = 0; i < n; i++) {
            A[i] = Double.parseDouble(tokenizer.nextToken());
        }
        return A[n - 1];
    }

    private static double[] nextDoubleArray(int n) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        double[] A = new double[n];
        for (int i = 0; i < n; i++) {
            A[i] = Double.parseDouble(tokenizer.nextToken());
        }
        return A;
    }

    private static String nextString() throws IOException {
        return reader.readLine();
    }

    private static String nextString(int n) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        String[] A = new String[n];
        for (int i = 0; i < n; i++) {
            A[i] = tokenizer.nextToken();
        }
        return A[n - 1];
    }

    private static String[] nextStringArray(int n) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        String[] A = new String[n];
        for (int i = 0; i < n; i++) {
            A[i] = tokenizer.nextToken();
        }
        return A;
    }

    private static int max(int a, int b) {
        return a > b ? a : b;
    }

    private static int min(int a, int b) {
        return a < b ? a : b;
    }

    private static long max(long a, long b) {
        return a > b ? a : b;
    }

    private static long min(long a, long b) {
        return a < b ? a : b;
    }

    private static double max(double a, double b) {
        return a > b ? a : b;
    }

    private static double min(double a, double b) {
        return a < b ? a : b;
    }

    private static int abs(int a) {
        return a < 0 ? -a : a;
    }

    private static long abs(long a) {
        return a < 0 ? -a : a;
    }

    private static double abs(double a) {
        return a < 0 ? -a : a;
    }

    private static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }

    private static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    private static int pow(int a, int b) {
        return b == 0 ? 1 : a * pow(a, b - 1);
    }

    private static long pow(long a, long b) {
        return b == 0 ? 1 : a * pow(a, b - 1);
    }

    private static double pow(double a, double b) {
        return b == 0 ? 1 : a * pow(a, b - 1);
    }

    private static int divUp(int a, int b) {
        return (a + b - 1) / b;
    }

    private static long divUp(long a, long b) {
        return (a + b - 1) / b;
    }

    private static int divDown(int a, int b) {
        return a / b;
    }

    private static long divDown(long a, long b) {
        return a / b;
    }

    private static int mod(int a, int b) {
        return a % b;
    }

    private static long mod(long a, long b) {
        return a % b;
    }

    private static int mod(int a, int b, int c) {
        return (a - b + c) % c;
    }

    private static long mod(long a, long b, long c) {
        return (a - b + c) % c;
    }

    private static int mod(int a, int b, int c, int d) {
        return (a - b + c - d) % d;
    }

    private static long mod(long a, long b, long c, long d) {
        return (a - b + c - d) % d;
    }

    private static int mod(int a, int b, int c, int d, int e) {
        return (a - b + c - d + e) % e;
    }

    private static long mod(long a, long b, long c, long d, long e) {
        return (a - b + c - d + e) % e;
    }

    private static int mod(int a, int b, int c, int d, int e, int f) {
        return (a - b + c - d + e - f) % f;
    }

    private static long mod(long a, long b, long c, long d, long e, long f) {
        return (a - b + c - d + e - f) % f;
    }

    private static int mod(int a, int b, int c, int d, int e, int f, int g) {
        return (a - b + c - d + e - f + g) % g;
    }

    private static long mod(long a, long b, long c, long d, long e, long f, long g) {
        return (a - b + c - d + e - f + g) % g;
    }

    private static int mod(int a, int b, int c, int d, int e, int f, int g, int h) {
        return (a - b + c - d + e - f + g - h) % h;
    }

    private static long mod(long a, long b, long c, long d, long e, long f, long g, long h) {
        return (a - b + c - d + e - f + g - h) % h;
    }

    private static int mod(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
        return (a - b + c - d + e - f + g - h + i) % i;
    }

    private static long mod(long a, long b, long c, long d, long e, long f, long g, long h, long i) {
        return (a - b + c - d + e - f + g - h + i) % i;
    }

    private static int mod(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
        return (a - b + c - d + e - f + g - h + i - j) % j;
    }

    private static long mod(long a, long b, long c, long d, long e, long f, long g, long h, long i, long j) {
        return (a - b + c - d + e - f + g - h + i - j) % j;
    }

    private static int mod(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
        return (a - b + c - d + e - f + g - h + i - j + k) % k;
    }

    private static long mod(long a, long b, long c, long d, long e, long f, long g, long h, long i, long j, long k) {
        return (a - b + c - d + e - f + g - h + i - j + k) % k;
    }

    private static int mod(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
        return (a - b + c - d + e - f + g - h + i - j + k - l) % l;
    }

    private static long mod(long a, long b, long c, long d, long e, long f, long g, long h, long i, long j, long k, long l) {
        return (a - b + c - d + e - f + g - h + i - j + k - l) % l;
    }

    private static int mod(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m) {
        return (a - b + c - d + e - f + g - h + i - j + k - l + m) % m;
    }

    private static long mod(long a, long b, long c, long d, long e, long f, long g, long h, long i, long j, long k, long l, long m) {
        return (a - b + c - d + e - f + g - h + i - j + k - l + m) % m;
    }

    private static int mod(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
        return (a - b + c - d + e - f + g - h + i - j + k - l + m - n) % n;
    }

    private static long mod(long a, long b, long c, long d, long e, long f, long g, long h, long i, long j, long k, long l, long m, long n) {
        return (a - b + c - d + e - f + g - h + i - j + k - l + m - n) % n;
    }

    private static int mod