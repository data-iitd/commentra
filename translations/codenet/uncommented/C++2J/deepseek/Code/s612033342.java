public class Main {
    public static int pow2(int a) {
        int ret = 1;
        for (int i = 0; i < a; i++) ret *= 2;
        return ret;
    }

    public static int count(int[][] hw, int a, int b) {
        int sum = 0;
        for (int i = 0; i < hw.length; i++) {
            for (int j = 0; j < hw[0].length; j++) {
                if ((a & (1 << i)) != 0 && (b & (1 << j)) != 0 && hw[i][j] == 1) sum++;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int k = scanner.nextInt();
        int[][] hw = new int[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c = scanner.next().charAt(0);
                if (c == '#') hw[i][j] = 1;
            }
        }
        int sum = 0;
        for (int i = 0; i < pow2(h); i++) {
            for (int j = 0; j < pow2(w); j++) {
                if (count(hw, i, j) == k) sum++;
            }
        }
        System.out.println(sum);
    }
}
