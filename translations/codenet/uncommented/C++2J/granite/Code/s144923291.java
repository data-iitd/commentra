
import java.util.*;
import java.io.*;

class s144923291 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        int w = sc.nextInt();
        String s = "snuke";
        char[][] t = new char[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                t[i][j] = sc.next().charAt(0);
                if (s.equals(String.valueOf(t[i][j]))) {
                    char c = (char) ('A' + j);
                    System.out.println(c + (i + 1));
                    return;
                }
            }
        }
    }
}

