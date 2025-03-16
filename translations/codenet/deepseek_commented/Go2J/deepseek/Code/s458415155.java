public class Main {
    static class Scanner {
        private java.util.Scanner scanner;

        public Scanner(java.io.InputStream inputStream) {
            scanner = new java.util.Scanner(inputStream);
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
        int[] t = new int[n];
        java.util.Arrays.fill(t, Integer.MAX_VALUE);
        t[0] = 0;

        for (int i = 1; i < n; i++) {
            if (t[i - 1] + abs(heights[i] - heights[i - 1]) < t[i]) {
                t[i] = t[i - 1] + abs(heights[i] - heights[i - 1]);
            }
            if (i > 1 && t[i - 2] + abs(heights[i] - heights[i - 2]) < t[i]) {
                t[i] = t[i - 2] + abs(heights[i] - heights[i - 2]);
            }
        }

        return t[n - 1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heights = sc.nextIntArray(n);
        int ans = solve(n, heights);
        System.out.println(ans);
    }
}
