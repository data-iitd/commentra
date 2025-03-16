import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = nextInt(scanner);
        int[] h = nextInts(scanner, N);
        
        int[] dp = new int[N];
        dp[0] = 0; // Initialize the first element
        if (N > 1) {
            dp[1] = Abs(h[0] - h[1]);
        }
        
        for (int i = 2; i < N; i++) {
            dp[i] = Min(new int[]{
                dp[i - 1] + Abs(h[i] - h[i - 1]),
                dp[i - 2] + Abs(h[i] - h[i - 2])
            });
        }
        
        System.out.println(dp[N - 1]);
    }

    public static int Max(int[] a) {
        int r = a[0];
        for (int value : a) {
            if (r < value) {
                r = value;
            }
        }
        return r;
    }

    public static int Min(int[] a) {
        int r = a[0];
        for (int value : a) {
            if (r > value) {
                r = value;
            }
        }
        return r;
    }

    public static int Sum(int[] a) {
        int r = 0;
        for (int value : a) {
            r += value;
        }
        return r;
    }

    public static int Abs(int a) {
        return a < 0 ? -a : a;
    }

    public static int nextInt(Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }

    public static int[] nextInts(Scanner scanner, int n) {
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = nextInt(scanner);
        }
        return r;
    }
}

// <END-OF-CODE>
