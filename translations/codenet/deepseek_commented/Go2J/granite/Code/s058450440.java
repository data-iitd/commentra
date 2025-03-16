
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s058450440{
    private static int[] a;
    private static int ans;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] chars = br.readLine().split("");
        int[] counts = new int[5];
        for (String c : chars) {
            switch (c) {
                case "M":
                    counts[0]++;
                    break;
                case "A":
                    counts[1]++;
                    break;
                case "R":
                    counts[2]++;
                    break;
                case "C":
                    counts[3]++;
                    break;
                case "H":
                    counts[4]++;
                    break;
            }
        }
        a = Arrays.stream(counts).filter(count -> count > 0).toArray();
        dfs(3, 0, 1);
        System.out.println(ans);
    }

    private static void dfs(int left, int i, int res) {
        if (left == 0) {
            ans += res;
            return;
        }
        for (int j = i; j < a.length; j++) {
            dfs(left - 1, j + 1, res * a[j]);
        }
    }
}

// 