import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = reader.readLine().split(" ");
        int N = Integer.parseInt(nm[0]);
        int M = Integer.parseInt(nm[1]);

        String[] A_str = reader.readLine().split(" ");
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(A_str[i]);
        }

        long[] cumRemainders = new long[N + 1];
        cumRemainders[0] = 0;
        for (int i = 1; i <= N; i++) {
            cumRemainders[i] = (cumRemainders[i - 1] + A[i - 1]) % M;
        }

        Map<Long, Integer> remainderCounts = new HashMap<>();
        for (long remainder : cumRemainders) {
            remainderCounts.put(remainder, remainderCounts.getOrDefault(remainder, 0) + 1);
        }

        long combinations = 0;
        for (int count : remainderCounts.values()) {
            combinations += (long) count * (count - 1) / 2;
        }

        System.out.println(combinations);
    }
}
