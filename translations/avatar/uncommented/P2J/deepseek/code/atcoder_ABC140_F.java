import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] S_input = br.readLine().split(" ");
        Integer[] S = new Integer[N];
        for (int i = 0; i < N; i++) {
            S[i] = Integer.parseInt(S_input[i]);
        }
        Arrays.sort(S, Collections.reverseOrder());
        boolean[] flag = new boolean[N];
        List<Integer> cur = new ArrayList<>();
        cur.add(S[0]);
        flag[0] = false;
        for (int i = 0; i < N; i++) {
            int j = 0;
            int jM = cur.size();
            for (int k = 0; k < N; k++) {
                if (flag[k] && S[k] < cur.get(j)) {
                    cur.add(S[k]);
                    j++;
                    flag[k] = false;
                    if (j == jM) {
                        break;
                    }
                }
            }
            if (j == jM) {
                System.out.println("No");
                return;
            }
            Collections.sort(cur, Collections.reverseOrder());
        }
        System.out.println("Yes");
    }
}
