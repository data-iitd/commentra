
import java.util.*;

public class s497500962{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int G = sc.nextInt();
        int B = sc.nextInt();
        int N = sc.nextInt();
        int ans = 0;
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                int tmp = N - R * x - G * y;
                if (tmp >= 0 && tmp % B == 0) {
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}

// Input related functions
static int nextInt() {
    return Integer.parseInt(sc.next());
}

static float nextFloat() {
    return Float.parseFloat(sc.next());
}

static String nextString() {
    return sc.next();
}

// Utility functions
static int abs(int x) {
    return (int) Math.abs(x);
}

static int min(int x, int y) {
    return (int) Math.min(x, y);
}

static int max(int x, int y) {
    return (int) Math.max(x, y);
}

