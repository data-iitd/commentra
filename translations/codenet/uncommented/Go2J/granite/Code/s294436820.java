
import java.io.*;
import java.util.*;

public class s294436820{
    public static void main(String[] args) throws IOException {
        SetInput(System.in);
        SetOutput(System.out);

        int h = readi();
        int w = readi();
        int k = readi();
        int[][] m = new int[h][w];
        for (int i = 0; i < h; i++) {
            String s = reads();
            for (int j = 0; j < w; j++) {
                m[i][j] = s.charAt(j) - '0';
            }
        }

        int answer = solve(h, w, k, m);
        println(answer);
    }

    public static final int Black = 35;

    public static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        debug("new table");
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == Black) {
                    count++;
                }
            }
            debug(Arrays.toString(m[i]));
        }
        debug("result : ", count);
        return count;
    }

    public static int solve(int h, int w, int a, int[][] m) {
        int result = 0;
        for (int i = 0; i < 1 << h; i++) {
            for (int k = 0; k < 1 << w; k++) {
                int[][] tmp = new int[h][w];
                for (int j = 0; j < h; j++) {
                    System.arraycopy(m[j], 0, tmp[j], 0, w);
                }
                for (int j = 0; j < h; j++) {
                    int hPainted = (1 << j & i);
                    if (hPainted > 0) {
                        debug("painted ", j, 1 << j, i, hPainted);
                        for (int l = 0; l < w; l++) {
                            tmp[j][l] = 1;
                        }
                    }
                }
                for (int j = 0; j < w; j++) {
                    int wPainted = (1 << j & k);
                    if (wPainted > 0) {
                        for (int l = 0; l < h; l++) {
                            tmp[l][j] = 1;
                        }
                    }
                }
                debug("i", Integer.toBinaryString(i));
                debug("k", Integer.toBinaryString(k));
                if (countBlack(h, w, tmp) == a) {
                    result++;
                }
            }
        }
        return result;
    }
}

