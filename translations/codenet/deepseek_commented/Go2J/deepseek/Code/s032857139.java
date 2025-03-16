import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    static String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    static int nextInt() {
        return Integer.parseInt(next());
    }

    static long nextLong() {
        return Long.parseLong(next());
    }

    static double nextDouble() {
        return Double.parseDouble(next());
    }

    static String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    static int[] readArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }

    static void printArray(int[] a) {
        for (int i : a) out.print(i + " ");
        out.println();
    }

    static void printlnArray(int[] a) {
        for (int i : a) out.println(i);
    }

    static void printMatrix(int[][] mat) {
        for (int[] row : mat) {
            for (int val : row) out.print(val + " ");
            out.println();
        }
    }

    static void printlnMatrix(int[][] mat) {
        for (int[] row : mat) {
            for (int val : row) out.println(val);
        }
    }

    static int max(int... a) {
        return Arrays.stream(a).max().getAsInt();
    }

    static int min(int... a) {
        return Arrays.stream(a).min().getAsInt();
    }

    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static int lcm(int a, int b) {
        return a * (b / gcd(a, b));
    }

    static boolean isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    static int pow(int a, int e) {
        int res = 1;
        while (e > 0) {
            if ((e & 1) == 1) res = res * a;
            a = a * a;
            e >>= 1;
        }
        return res;
    }

    static int modpow(int a, int e, int mod) {
        int res = 1;
        while (e > 0) {
            if ((e & 1) == 1) res = res * a % mod;
            a = a * a % mod;
            e >>= 1;
        }
        return res;
    }

    static int modinv(int a, int mod) {
        return modpow(a, mod - 2, mod);
    }

    static int mod(int val, int m) {
        int res = val % m;
        if (res < 0) res += m;
        return res;
    }

    static class IntHeap {
        int[] heap;
        int size;

        IntHeap(int capacity) {
            heap = new int[capacity];
            size = 0;
        }

        void add(int val) {
            if (size == heap.length) {
                heap = Arrays.copyOf(heap, 2 * heap.length);
            }
            heap[size++] = val;
            int i = size - 1;
            while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
                int temp = heap[i];
                heap[i] = heap[(i - 1) / 2];
                heap[(i - 1) / 2] = temp;
                i = (i - 1) / 2;
            }
        }

        int poll() {
            if (size == 0) throw new NoSuchElementException();
            int res = heap[0];
            heap[0] = heap[--size];
            int i = 0;
            while (2 * i + 1 < size) {
                int left = 2 * i + 1, right = 2 * i + 2;
                int smaller = left;
                if (right < size && heap[right] < heap[left]) {
                    smaller = right;
                }
                if (heap[i] <= heap[smaller]) break;
                int temp = heap[i];
                heap[i] = heap[smaller];
                heap[smaller] = temp;
                i = smaller;
            }
            return res;
        }

        boolean isEmpty() {
            return size == 0;
        }
    }

    public static void main(String[] args) {
        int n = nextInt(), x = nextInt();
        int[] A = readArray(n);

        Arrays.sort(A);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
            } else {
                break;
            }
        }
        if (ans == n && x > 0) {
            ans--;
        }
        out.println(ans);
        out.flush();
    }
}
