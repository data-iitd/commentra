import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        char[][] t = new char[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                t[i][j] = scanner.next().charAt(0);
            }
        }
        char[] s = "snuke".toCharArray();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (t[i][j] == s[0]) {
                    boolean found = true;
                    for (int k = 1; k < s.length && found; k++) {
                        if (i + k < h && t[i + k][j] == s[k]) {
                            continue;
                        } else if (j + k < w && t[i][j + k] == s[k]) {
                            continue;
                        } else {
                            found = false;
                        }
                    }
                    if (found) {
                        char c = (char) ('A' + j);
                        System.out.println(c + "" + (i + 1));
                        return;
                    }
                }
            }
        }
    }
}
