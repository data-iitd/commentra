
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        double t = Double.parseDouble(st.nextToken());
        double a = Double.parseDouble(st.nextToken());
        double[] heights = new double[n];
        for (int i = 0; i < n; i++) {
            heights[i] = Double.parseDouble(br.readLine());
        }
        double minDiff = Math.abs(t - heights[0] * 0.006 - a);
        int minIdx = 0;
        for (int i = 1; i < n; i++) {
            double diff = Math.abs(t - heights[i] * 0.006 - a);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }
        System.out.println(minIdx + 1);
    }
}

