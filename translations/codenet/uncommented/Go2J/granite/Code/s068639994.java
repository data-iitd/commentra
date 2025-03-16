
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Scanner;

public class s068639994{
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = scanner.nextInt();
        int[] ls = new int[n];
        for (int i = 0; i < n; i++) {
            ls[i] = scanner.nextInt();
        }

        int[] lsRev = Arrays.copyOf(ls, n);
        Arrays.sort(ls);
        Arrays.sort(lsRev);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = Math.min(ls[i], ls[j]);
                int q = Math.max(ls[i], ls[j]);
                int x = q - p;
                int y = q + p;

                int l = Arrays.binarySearch(ls, x);
                if (l < 0) {
                    l = -l - 1;
                }
                int r = Arrays.binarySearch(lsRev, y);
                if (r < 0) {
                    r = -r - 1;
                }

                int sum = r - l;
                if (i >= l && i <= r) {
                    sum--;
                }
                if (j >= l && j <= r) {
                    sum--;
                }
                sum = Math.max(0, sum);
                ans += sum;
            }
        }

        ans /= 3;
        writer.write(String.valueOf(ans));
        writer.newLine();
        writer.flush();
    }
}

