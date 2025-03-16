import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine());
        String[] input = reader.readLine().split(" ");
        int[] v = new int[N];

        for (int i = 0; i < N; i++) {
            int a = Integer.parseInt(input[i]);
            v[a - 1]++;
        }

        PrintWriter writer = new PrintWriter(System.out);
        for (int e : v) {
            writer.println(e);
        }
        writer.flush();
    }
}

