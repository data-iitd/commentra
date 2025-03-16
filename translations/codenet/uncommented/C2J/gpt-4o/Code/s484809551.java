import java.util.Scanner;

public class Main {
    private static final String PATTERN_BASE = "keyence";

    private static String strrstr(String string, String pattern) {
        int offset = 0;
        String lastP = null;

        while (true) {
            int index = string.indexOf(pattern, offset);
            if (index == -1) {
                break;
            }
            lastP = string.substring(index);
            offset = index + 1;
        }

        return lastP;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        scanner.close();

        boolean found = false;

        for (int offset = 0; offset <= PATTERN_BASE.length(); offset++) {
            String top = PATTERN_BASE.substring(0, offset);
            String bottom = PATTERN_BASE.substring(offset);

            int topSearchIndex = S.indexOf(top);
            if (topSearchIndex != -1) {
                String bottomSearch = strrstr(S.substring(topSearchIndex + offset), bottom);
                if (bottomSearch != null) {
                    int sepCount = 0;

                    if (topSearchIndex != 0) {
                        sepCount++;
                    }
                    if (topSearchIndex + offset < S.length() && !bottomSearch.isEmpty()) {
                        sepCount++;
                    }
                    if (topSearchIndex + offset + bottom.length() < S.length()) {
                        sepCount++;
                    }

                    if (sepCount <= 1) {
                        found = true;
                        break;
                    }
                }
            }
        }

        System.out.println(found ? "YES" : "NO");
    }
}
// <END-OF-CODE>
