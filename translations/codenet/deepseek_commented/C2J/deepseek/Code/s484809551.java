public class KeyencePattern {
    public static void main(String[] args) {
        String patternBase = "keyence";
        String S;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        S = scanner.nextLine();
        boolean found = false;

        for (int offset = 0; offset < patternBase.length(); offset++) {
            String top = patternBase.substring(0, offset);
            String bottom = patternBase.substring(offset);

            int topIndex = S.indexOf(top);
            if (topIndex != -1) {
                int bottomIndex = S.lastIndexOf(bottom, S.length() - 1);
                if (bottomIndex != -1) {
                    int sepCount = 0;

                    if (topIndex != 0) {
                        sepCount++;
                    }
                    if (S.length() - (topIndex + top.length()) != bottomIndex - (topIndex + top.length())) {
                        sepCount++;
                    }
                    if (bottomIndex != S.length() - bottom.length()) {
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
