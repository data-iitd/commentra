import java.util.Scanner;

public class Main {
    static class ScannerWrapper {
        private Scanner scanner;

        public ScannerWrapper(Scanner scanner) {
            this.scanner = scanner;
        }

        public int nextInt() {
            return scanner.nextInt();
        }

        public int[] nextIntArray(int size) {
            int[] array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = scanner.nextInt();
            }
            return array;
        }
    }

    public static int abs(int x) {
        return x < 0 ? -x : x;
    }

    public static int solve(int n, int[] heights) {
        int[] t = new int[n + 1];
        for (int i = 0; i < t.length; i++) {
            t[i] = Integer.MAX_VALUE;
        }

        t[0] = 0;
        for (int i = 1; i < n; i++) {
            if (t[i - 1] + abs(heights[i] - heights[i - 1]) < t[i]) {
                t[i] = t[i - 1] + abs(heights[i] - heights[i - 1]);
            }
            if (i > 1) {
                if (t[i - 2] + abs(heights[i] - heights[i - 2]) < t[i]) {
                    t[i] = t[i - 2] + abs(heights[i] - heights[i - 2]);
                }
            }
        }

        return t[n - 1];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ScannerWrapper scannerWrapper = new ScannerWrapper(scanner);
        int n = scannerWrapper.nextInt();
        int[] heights = scannerWrapper.nextIntArray(n);
        int ans = solve(n, heights);
        System.out.println(ans);
    }
}
