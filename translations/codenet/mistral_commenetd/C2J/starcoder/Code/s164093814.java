
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int M = 1046527, L = 14, i, n, hash, key, h1, h2;
        String H[][] = new String[M][L];
        for (i = 0; i < M; i++) {
            for (int j = 0; j < L; j++) {
                H[i][j] = "";
            }
        }
        n = sc.nextInt();
        for (i = 0; i < n; i++) {
            String com = sc.next();
            String str = sc.next();
            if (com.charAt(0) == 'i') {
                key = getKey(str);
                h1 = key % M;
                h2 = 1 + (key % (M - 1));
                for (int j = 0; j < M; j++) {
                    hash = (h1 + j * h2) % M;
                    if (H[hash].equals("")) {
                        H[hash] = str;
                        break;
                    }
                }
            } else {
                key = getKey(str);
                h1 = key % M;
                h2 = 1 + (key % (M - 1));
                for (int j = 0; j < M; j++) {
                    hash = (h1 + j * h2) % M;
                    if (H[hash].equals(str)) {
                        System.out.println("yes");
                        break;
                    }
                }
                if (j == M) {
                    System.out.println("no");
                }
            }
        }
    }

    public static int getChar(char ch) {
        if (ch == 'A')
            return 1;
        else if (ch == 'C')
            return 2;
        else if (ch == 'G')
            return 3;
        else if (ch == 'T')
            return 4;
        return 0;
    }

    public static long long getKey(String str) {
        long long sum = 0, p = 1;
        for (int i = 0; i < str.length(); i++) {
            sum += p * (getChar(str.charAt(i)));
            p *= 5;
        }
        return sum;
    }
}

