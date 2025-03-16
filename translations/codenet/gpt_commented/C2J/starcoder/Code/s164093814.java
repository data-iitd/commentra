
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] str = new String[100000];
        String[] com = new String[100000];
        for (int i = 0; i < n; i++) {
            com[i] = sc.next();
            str[i] = sc.next();
        }
        int M = 1046527;
        int L = 14;
        String[][] H = new String[M][L];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < L; j++) {
                H[i][j] = "";
            }
        }
        int getChar(char ch) {
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
        long long getKey(String str) {
            long long sum = 0, p = 1;
            for (int i = 0; i < str.length(); i++) {
                sum += p * (getChar(str.charAt(i)));
                p *= 5;
            }
            return sum;
        }
        int h1(int key) {
            return key % M;
        }
        int h2(int key) {
            return 1 + (key % (M - 1));
        }
        int find(String str) {
            int i, hash, key;
            key = getKey(str);
            i = 0;
            while (1) {
                hash = (h1(key) + i * h2(key)) % M;
                if (H[hash].equals(str))
                    return 1;
                else if (H[hash].equals(""))
                    return 0;
                i++;
            }
        }
        int insert(String str) {
            int i, hash, key;
            key = getKey(str);
            i = 0;
            while (1) {
                hash = (h1(key) + i * h2(key)) % M;
                if (H[hash].equals(str))
                    return 1;
                else if (H[hash].equals("")) {
                    H[hash] = str;
                    return 0;
                }
                i++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (com[i].charAt(0) == 'i') {
                insert(str[i]);
            } else {
                if (find(str[i]))
                    System.out.println("yes");
                else
                    System.out.println("no");
            }
        }
    }
}

