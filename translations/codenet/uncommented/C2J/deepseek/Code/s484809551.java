public class Main {
    public static void main(String[] args) {
        String patternBase = "keyence";
        String S = new java.util.Scanner(System.in).nextLine();

        boolean found = false;

        for (int offset = 0; offset < patternBase.length(); offset++) {
            String top = patternBase.substring(0, offset);
            String bottom = patternBase.substring(offset);

            int topIndex = S.indexOf(top);
            if (topIndex != -1) {
                int bottomIndex = S.lastIndexOf(bottom);
                if (bottomIndex != -1) {
                    int sepCount = 0;

                    if (topIndex != 0) {
                        sepCount++;
                    }
                    if (topIndex + top.length() != bottomIndex) {
                        sepCount++;
                    }
                    if (bottomIndex + bottom.length() != S.length()) {
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
