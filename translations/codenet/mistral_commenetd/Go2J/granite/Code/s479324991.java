
import java.util.*;
import java.io.*;

public class s479324991{
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        double[] arr = new double[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        double prev = arr[0];
        for (int i = 1; i < n; i++) {
            prev = (prev + arr[i]) / 2;
        }

        System.out.println(prev);
    }
}

// Initialize a new scanner object
class Scanner {
    BufferedReader r;
    StringTokenizer t;

    Scanner() {
        r = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() throws IOException {
        while (t == null ||!t.hasMoreTokens()) {
            t = new StringTokenizer(r.readLine());
        }
        return t.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    String nextLine() throws IOException {
        return r.readLine();
    }
}

