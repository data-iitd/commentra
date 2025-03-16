import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

public class Main {
    private static final Random rand = new Random();
    
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String N = reader.readLine();
        int n = 0;

        for (char c : N.toCharArray()) {
            n += c - '0';
        }

        int m = Integer.parseInt(N);
        if (m % n == 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    // Utility methods
    public static int max(int... a) {
        int r = a[0];
        for (int value : a) {
            if (r < value) {
                r = value;
            }
        }
        return r;
    }

    public static int min(int... a) {
        int r = a[0];
        for (int value : a) {
            if (r > value) {
                r = value;
            }
        }
        return r;
    }

    public static int sum(int[] a) {
        int r = 0;
        for (int value : a) {
            r += value;
        }
        return r;
    }

    public static int pro(int[] a) {
        int r = a[0];
        for (int i = 1; i < a.length; i++) {
            r *= a[i];
        }
        return r;
    }

    public static int[] fill(int[] a, int n) {
        for (int i = 0; i < a.length; i++) {
            a[i] = n;
        }
        return a;
    }

    public static int[] minmax(int a, int b) {
        return a > b ? new int[]{b, a} : new int[]{a, b};
    }

    public static int abs(int a) {
        return a < 0 ? -a : a;
    }

    public static int ceil(int a, int b) {
        return (a % b != 0) ? 1 : 0;
    }

    public static void printStrings(String[] out) {
        for (int i = 0; i < out.length; i++) {
            System.out.print(out[i]);
            if (i != out.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }

    public static void printInts(int[] out) {
        for (int i = 0; i < out.length; i++) {
            System.out.print(out[i]);
            if (i != out.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}
// <END-OF-CODE>
