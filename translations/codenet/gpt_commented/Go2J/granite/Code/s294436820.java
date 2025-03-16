

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class s294436820{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int h, w, k;
        int[][] m;
        int result = 0;

        h = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        w = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        m = new int[h][w];
        for (int i = 0; i < h; i++) {
            String s = br.readLine();
            for (int j = 0; j < w; j++) {
                m[i][j] = Integer.parseInt(s.substring(j, j + 1));
            }
        }

        result = solve(h, w, k, m);
        bw.write(Integer.toString(result));
        bw.newLine();

        bw.flush();
    }

    static int Black = 35;

    static int countBlack(int h, int w, int[][] m) {
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] == Black) {
                    count++;
                }
            }
        }
        return count;
    }

    static int solve(int h, int w, int a, int[][] m) {
        int result = 0;
        for (int i = 0; i < (1 << h); i++) {
            for (int k = 0; k < (1 << w); k++) {
                int tmp[][] = new int[h][w];
                for (int j = 0; j < h; j++) {
                    for (int l = 0; l < w; l++) {
                        tmp[j] = Arrays.copyOf(m[j], w);
                    }
                }
                int hPainted = (1 << j & i);
                if (hPainted > 0) {
                    for (int l = 0; l < w; l++) {
                        tmp[l] = Arrays.copyOf(m[l], w);
                    }
                }
                int wPainted = (1 << j & k);
                if (wPainted > 0) {
                    for (int l = 0; l < h; l++) {
                        tmp[l] = Arrays.copyOf(m[l], w);
                    }
                }
                int count = 0;
                for (int l = 0; l < w; l++) {
                        count += countBlack(h, w, tmp);
                    }
                }
                int result = 0;
                for (int l = 0; l < h; l++) {
                        result++
                    }
                }
                return result;
            }
        }
    }
}

func main() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;

    int h, w, k;
    int[][] m;
    int result = 0;

    h = Integer.parseInt(br.readLine());
    st = new StringTokenizer(br.readLine());
    w = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());
    m = new int[h][w];
    result = solve(h, w, k, m);
    bw.write(Integer.toString(result));
    bw.newLine();
    bw.flush();
}

func main() {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    StringTokenizer st;

    int h, w, k;
    int[][] m;
    int result = 0;

    h = Integer.parseInt(br.readLine());
    st = new StringTokenizer(br.readLine());
    w = Integer.parseInt(st.nextToken());
    k = Integer.parseInt(st.nextToken());
    m = new int[h][w];
    result = solve(h, w, k, m);
    bw.write(Integer.toString(result));
    bw.newLine();
    bw.flush();
}