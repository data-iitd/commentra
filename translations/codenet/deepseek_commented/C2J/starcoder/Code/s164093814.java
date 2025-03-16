
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] str = new String[n];
        String[] com = new String[n];
        for (int i = 0; i < n; i++) {
            str[i] = sc.next();
            com[i] = sc.next();
        }
        int M = 1046527;
        int L = 14;
        String[][] H = new String[M][L];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < L; j++) {
                H[i][j] = "";
            }
        }
        for (int i = 0; i < n; i++) {
            if (com[i].charAt(0) == 'i') {
                insert(str[i], H);
            } else {
                if (find(str[i], H)) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            }
        }
    }

    public static void insert(String str, String[][] H) {
        int key = getKey(str);
        int i = 0;
        while (true) {
            int hash = (h1(key) + i * h2(key)) % M;
            if (H[hash].equals(str)) {
                return;
            } else if (H[hash].equals("")) {
                H[hash] = str;
                return;
            }
            i++;
        }
    }

    public static boolean find(String str, String[][] H) {
        int key = getKey(str);
        int i = 0;
        while (true) {
            int hash = (h1(key) + i * h2(key)) % M;
            if (H[hash].equals(str)) {
                return true;
            } else if (H[hash].equals("")) {
                return false;
            }
            i++;
        }
    }

    public static int getKey(String str) {
        int sum = 0, p = 1;
        for (int i = 0; i < str.length(); i++) {
            sum += p * getChar(str.charAt(i));
            p *= 5;
        }
        return sum;
    }

    public static int getChar(char ch) {
        if (ch == 'A') {
            return 1;
        } else if (ch == 'C') {
            return 2;
        } else if (ch == 'G') {
            return 3;
        } else if (ch == 'T') {
            return 4;
        }
        return 0;
    }

    public static int h1(int key) {
        return key % M;
    }

    public static int h2(int key) {
        return 1 + (key % (M - 1));
    }
}

