
import java.io.*;
import java.util.*;

public class s541050824{
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        long[] T = new long[N];
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            String[] line = br.readLine().split(" ");
            T[i] = Long.parseLong(line[0]);
            A[i] = Long.parseLong(line[1]);
        }
        long t = T[0];
        long a = A[0];
        for (int i = 1; i < N; i++) {
            long r = Math.max(t / T[i], a / A[i]);
            t = T[i] * r;
            a = A[i] * r;
        }
        bw.write(Long.toString(t + a));
        bw.newLine();

        bw.flush();
    }
}

