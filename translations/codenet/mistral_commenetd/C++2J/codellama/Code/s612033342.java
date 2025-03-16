
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        int k = sc.nextInt();
        int[][] hw = new int[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c = sc.next().charAt(0);
                if (c == '#') {
                    hw[i][j] = 1;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < (int) Math.pow(2, h); i++) {
            for (int j = 0; j < (int) Math.pow(2, w); j++) {
                if (count(hw, i, j) == k) {
                    sum++;
                }
            }
        }
        System.out.println(sum);
    }

    public static int count(int[][] hw, int a, int b) {
        int sum = 0;
        for (int i = 0; i < hw.length; i++) {
            for (int j = 0; j < hw[0].length; j++) {
                if ((a & (1 << i)) != 0 && (b & (1 << j)) != 0 && hw[i][j] == 1) {
                    sum++;
                }
            }
        }
        return sum;
    }
}

