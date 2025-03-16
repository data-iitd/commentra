
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class s753839476{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = scanner.nextInt();
        double t = scanner.nextDouble();
        double a = scanner.nextDouble();
        double[] heights = new double[n];
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextDouble();
        }

        double minDiff = Math.abs(t - heights[0] * 0.006 - a);
        int minIdx = 0;
        for (int i = 1; i < n; i++) {
            double diff = Math.abs(t - heights[i] * 0.006 - a);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i + 1;
            }
        }
        writer.write(String.valueOf(minIdx));
        writer.flush();
    }
}

