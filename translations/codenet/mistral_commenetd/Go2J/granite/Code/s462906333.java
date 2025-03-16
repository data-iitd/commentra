
// Importing necessary packages
import java.util.*;
import java.io.*;

// Constants and variables declaration
final int inf = 1000000000;

// var mod = 1000000007;

// s462906333 function
public class s462906333{
    // Function to read input from standard input using buffered reader
    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() throws IOException {
            while (st == null ||!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public int[] nextArr(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        public Integer[] nextsortArr(int n) throws IOException {
            Integer[] arr = new Integer[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }

    // Function to check if a given number is inside a given range
    static boolean in(int c, int a, int z) {
        return c >= a && c < z;
    }

    // Function to convert boolean value to integer
    static int btoi(boolean b) {
        if (b) {
            return 1;
        }
        return 0;
    }

    // Function to convert integer value to boolean
    static boolean itob(int a) {
        if (a == 0) {
            return false;
        }
        return true;
    }

    // s462906333 function
    public static void main(String[] args) throws IOException {
        // Setting up logging
        Scanner sc = new Scanner();
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] a = new int[n];
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            v[i] = a[i];
        }
        int ans = inf;
        for (int k = 0; k < n; k++) {
            int kans = 0;
            for (int i = 0; i < n; i++) {
                if (i - k < 0) {
                    v[i] = Math.min(v[i], a[n + i - k]);
                } else {
                    v[i] = Math.min(v[i], a[i - k]);
                }
                kans += v[i];
            }
            ans = Math.min(ans, kans + k * x);
        }
        System.out.println(ans);
    }
}

// -------------------------------
// 