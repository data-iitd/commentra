
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter wr = new PrintWriter(System.out);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        int sum = IntStream.of(a).sum();
        int count = 0;
        for (int v : a) {
            double rate = (double) sum / (4 * m);
            if (v >= rate) {
                count++;
            }
        }

        if (count >= m) {
            wr.println("Yes");
        } else {
            wr.println("No");
        }

        wr.flush();
    }
}

