
import java.util.Scanner;

public class s484809551{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String patternBase = "keyence";
        String top = "", bottom = "";
        String S = scanner.nextLine();
        int len = S.length();
        boolean found = false;

        for (int offset = 0; offset < patternBase.length(); offset++) {
            top = patternBase.substring(0, offset);
            bottom = patternBase.substring(offset);

            int topIndex = S.indexOf(top);
            if (topIndex!= -1) {
                int bottomIndex = S.lastIndexOf(bottom);
                if (bottomIndex!= -1) {
                    int sepCount = 0;

                    if (topIndex!= 0) {
                        sepCount++;
                    }
                    if (bottomIndex!= topIndex + offset) {
                        sepCount++;
                    }
                    if (bottomIndex + bottom.length()!= len) {
                        sepCount++;
                    }

                    if (sepCount <= 1) {
                        found = true;
                        break;
                    }
                }
            }
        }

        System.out.println(found? "YES" : "NO");
    }
}

