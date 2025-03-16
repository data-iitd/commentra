import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader _fin = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter _fout = new PrintWriter(new OutputStreamWriter(System.out));

    static final double PI = 3.141592653589793238462643383279502884197169399375105820974;
    static final int ten5p1 = 100001;
    static final int ten6p1 = 1000001;
    static final int ten8p1 = 100000001;
    static final int ten9p1 = 1000000001;

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int cmpPair(Pair a, Pair b) {
        if (a.x == b.x) {
            return a.y < b.y ? -1 : 1;
        }
        return a.x < b.x ? -1 : 1;
    }

    static void sortPair(Pair[] d, int n) {
        Arrays.sort(d, (a, b) -> cmpPair(a, b));
    }

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static void reverse(int[] data, int n) {
        for (int i = 0, k = n >> 1; i < k; i++) {
            int tmp = data[i];
            data[i] = data[n - i - 1];
            data[n - i - 1] = tmp;
        }
    }

    static int bsearch(int val, int[] data, int n) {
        if (data[0] > val) return -1;
        if (data[n - 1] < val) return n;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (data[mid] <= val) l = mid;
            else r = mid - 1;
        }
        if (data[r] != val) r++;
        return r;
    }

    static class Vec {
        int[] data;
        int size, n;

        Vec(int size) {
            data = new int[size];
            this.size = size;
            this.n = 0;
        }

        void resize() {
            int ns = (int) (size * 1.2f);
            data = Arrays.copyOf(data, ns);
            size = ns;
        }

        void add(int val) {
            if (n >= size) resize();
            data[n++] = val;
        }
    }

    static boolean isPalindrome(int[] a, int[] b, int n) {
        for (int i = 0; i < n; i++) {
            if (a[i] != b[n - i - 1]) return false;
        }
        return true;
    }

    static boolean isPalindrome(char[] a, char[] b, int n) {
        for (int i = 0; i < n; i++) {
            if (a[i] != b[n - i - 1]) return false;
        }
        return true;
    }

    static int expmod(int x, int n, int m) {
        int ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) ans = (ans * x) % m;
            x = (x * x) % m;
            n >>= 1;
        }
        return ans;
    }

    static int combmod(int n, int k, int m) {
        int ret = 1, div = 1;
        for (int i = 0; i < k; i++) {
            ret = (ret * (n - i)) % m;
            div = (div * (i + 1)) % m;
        }
        div = expmod(div, m - 2, m);
        return (ret * div) % m;
    }

    public static void main(String[] args) throws IOException {
        FastReader fr = new FastReader();
        int a = fr.nextInt();
        int b = fr.nextInt();

        if (a < b) {
            for (int i = 0; i < b; i++) {
                _fout.print(a);
            }
            _fout.println();
        } else {
            for (int i = 0; i < a; i++) {
                _fout.print(b);
            }
            _fout.println();
        }
        _fout.flush();
    }
}
