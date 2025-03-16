import java.util.*;

public class Main {
    // Custom input parser
    static class Parser {
        private final Scanner scanner = new Scanner(System.in);
        private final Queue<String> tokens = new LinkedList<>();

        public void tokenize() {
            while (scanner.hasNext()) {
                String line = scanner.nextLine();
                String[] parts = line.split(" ");
                for (String part : parts) {
                    if (!part.isEmpty()) {
                        tokens.add(part);
                    }
                }
            }
        }

        public String next() {
            return tokens.poll();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) {
        Parser parser = new Main().new Parser();
        parser.tokenize();

        int N = parser.nextInt();
        int K = parser.nextInt();
        String S = parser.next();

        int segCnt = 0;

        for (int i = 0; i < N - 1; i++) {
            if (S.charAt(i) != S.charAt(i + 1)) {
                segCnt++;
            }
        }

        int curHappy = N - 1 - segCnt;
        int ans;

        if (2 * K >= segCnt) {
            ans = N - 1;
        } else {
            ans = curHappy + 2 * K;
        }

        System.out.println(ans);
    }
}
