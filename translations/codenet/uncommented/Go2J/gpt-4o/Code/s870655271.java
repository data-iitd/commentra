import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int ans = 0;

        if (N == 1 && M == 1) {
            ans += 1;
        } else if (N > 1 && M > 1) {
            ans += (N - 2) * (M - 2);
        } else {
            ans += (N * M) - 2;
        }

        System.out.println(ans);
    }

    public static int max(int... x) {
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.max(x[i], res);
        }
        return res;
    }

    public static int min(int... x) {
        int res = x[0];
        for (int i = 1; i < x.length; i++) {
            res = Math.min(x[i], res);
        }
        return res;
    }

    public static int pow(int x, int y) {
        return (int) Math.pow(x, y);
    }

    public static int abs(int x) {
        return Math.abs(x);
    }

    public static int floor(int x) {
        return (int) Math.floor(x);
    }
}

// <END-OF-CODE>
