import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int X = Integer.parseInt(input[1]);
        List<Integer> A = new ArrayList<>();
        for (int i = 2; i < input.length; i++) {
            A.add(Integer.parseInt(input[i]));
        }

        List<Integer> S = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            S.add(A.get(i) + (i % 2 == 0 ? 0 : X));
        }

        int ans = Integer.MAX_VALUE;
        for (int k = 1; k <= N / 2; k++) {
            int E = k * X + 2 * S.stream().skip(N - 2 * k - 1).limit(k).collect(Collectors.summingInt(Integer::intValue));
            ans = Math.min(ans, E);
        }

        System.out.println(ans + N * X + 5 * S.get(N - 1));
    }
}

