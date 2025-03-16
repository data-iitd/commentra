
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class s918723842{
    public static void main(String[] args) {
        Scanner scanner = new Scanner();

        int H = scanner.nextInt();
        int W = scanner.nextInt();
        int N = scanner.nextInt();

        int A = Math.max(H, W);

        System.out.println((N + A - 1) / A);
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

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
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