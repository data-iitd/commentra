import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
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

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        int q = scanner.nextInt();
        int h = scanner.nextInt();
        int s = scanner.nextInt();
        int d = scanner.nextInt();
        int n = scanner.nextInt();

        // Calculate the best price for 1 liter of drink
        int best1L = Math.min(q * 4, Math.min(h * 2, s));

        // Calculate the best price for 2 liters of drink
        int best2L = Math.min(d, best1L * 2);

        // Calculate and print the total cost based on whether n is even or odd
        if (n % 2 == 0) {
            System.out.println(best2L * (n / 2)); // Total cost for even number of drinks
        } else {
            System.out.println(best2L * (n / 2) + best1L); // Total cost for odd number of drinks
        }
    }
}
