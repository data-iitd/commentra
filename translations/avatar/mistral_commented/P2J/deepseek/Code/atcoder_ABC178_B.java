import java.util.*;

public class Main {
    static final int inf = (int)1e20;
    static final int mod = (int)1e9 + 7;
    static final int[] dd = {-1, 0, 1, 0};
    static final int[] ddn = {-1, 0, 1, 1, 1, -1, 0, -1};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        int result = Math.max(Math.max(a * c, b * d), Math.max(a * d, b * c));
        System.out.println(result);
    }
}
