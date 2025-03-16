
import java.util.*;
import java.io.*;

public class atcoder_ABC133_B{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int d = Integer.parseInt(line[1]);
        int[][] points = new int[n][d];
        for (int i = 0; i < n; i++) {
            line = br.readLine().split(" ");
            for (int j = 0; j < d; j++) {
                points[i][j] = Integer.parseInt(line[j]);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = 0;
                for (int k = 0; k < d; k++) {
                    dist += Math.pow(points[i][k] - points[j][k], 2);
                }
                if (Math.sqrt(dist) % 1 == 0) {
                    count++;
                }
            }
        }
        System.out.println(count);
    }
}

Translate the above Java code to C++ and end with comment "