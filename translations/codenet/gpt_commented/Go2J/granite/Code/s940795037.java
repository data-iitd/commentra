
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class s940795037{
    public static void main(String[] args) {
        Scanner scanner = new Scanner();

        int n = scanner.nextInt();
        double ans = 0.0;

        for (int i = 0; i < n; i++) {
            int tmp = 1 / scanner.nextInt();
            ans += tmp;
        }

        System.out.println(1 / ans);
    }

    static class Scanner {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        List<String> tokens = new ArrayList<>();

        String next() {
            while (tokens.isEmpty()) {
                try {
                    tokens = new ArrayList<>(List.of(reader.readLine().split(" ")));
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            return tokens.remove(0);
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray() {
            return nextLine().split(" ").stream()
                   .mapToInt(Integer::parseInt)
                   .toArray();
        }

        String nextLine() {
            try {
                return reader.readLine();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return "";
        }
    }
}

// 