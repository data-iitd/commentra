
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int d = in.nextInt();
        int count = 0;
        int[][] points = new int[n][d];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                points[i][j] = in.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double distance = 0.0;
                for (int k = 0; k < d; k++) {
                    distance += Math.pow(points[i][k] - points[j][k], 2);
                }
                if (Math.sqrt(distance) % 1 == 0) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}

