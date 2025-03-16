
import java.util.*;
import java.io.*;

public class s753839476{
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        double t = Double.parseDouble(inputs[1]);
        double a = Double.parseDouble(inputs[2]);
        String[] heights = br.readLine().split(" ");
        double minDiff = Math.abs(t - Double.parseDouble(heights[0]) * 0.006 - a);
        int minIdx = 0;
        for (int i = 1; i < n; i++) {
            double diff = Math.abs(t - Double.parseDouble(heights[i]) * 0.006 - a);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i + 1;
            }
        }
        bw.write(Integer.toString(minIdx));
        bw.newLine();
        bw.flush();
    }
}

