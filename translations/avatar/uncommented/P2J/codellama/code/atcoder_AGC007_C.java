import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int ret = 0;
        while (N > 0) {
            ret += d + (N - 0.5) * x;
            d += d / N + 5 * x / (2 * N);
            x += 2 * x / N;
            N--;
        }
        System.out.println(ret);
    }
}



Translate the above Java code to C++ and end with comment "