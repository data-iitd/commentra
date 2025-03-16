import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] input = reader.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int d = Integer.parseInt(input[1]);
        int x = Integer.parseInt(input[2]);
        
        System.out.println(main(N, d, x));
    }

    public static double main(int N, int d, int x) {
        double ret = 0;
        while (N > 0) {
            ret += d + (N - 0.5) * x;
            d = d + (d / (double) N) + (5.0 * x) / (2.0 * N);
            x += 2 * x / N;
            N--;
        }
        return ret;
    }
}

// <END-OF-CODE>
