
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class s776764195{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int[] a = new int[n];
        for (int i = 1; i <= n; i++) {
            a[i - 1] = Integer.parseInt(str[i]);
        }

        int[] b = countingSort(a);

        for (int i = 0; i < n; i++) {
            pw.print(b[i]);
            if (i < n - 1) {
                pw.print(" ");
            }
        }
        pw.println();

        pw.flush();
        pw.close();
        br.close();
    }

    public static int[] countingSort(int[] a) {
        int k = 10001;
        int[] b = new int[a.length];
        int[] c = new int[k];
        for (int i = 0; i < a.length; i++) {
            c[a[i]]++;
        }
        for (int i = 1; i < k; i++) {
            c[i] += c[i - 1];
        }
        for (int i = a.length - 1; i >= 0; i--) {
            b[c[a[i]] - 1] = a[i];
            c[a[i]]--;
        }
        return b;
    }
}

