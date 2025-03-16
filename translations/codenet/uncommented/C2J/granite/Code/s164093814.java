
import java.util.Scanner;

public class s164093814{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int M = 1046527;
        int L = 14;
        String[] H = new String[M];
        for (int i = 0; i < M; i++) {
            H[i] = "";
        }

        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            String com = scanner.next();
            String str = scanner.next();
            if (com.equals("insert")) {
                insert(H, str);
            } else {
                if (find(H, str)) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            }
        }
    }

    public static int getChar(char ch) {
        if (ch == 'A') return 1;
        else if (ch == 'C') return 2;
        else if (ch == 'G') return 3;
        else if (ch == 'T') return 4;
        return 0;
    }

    public static long getKey(String str) {
        long sum = 0;
        int p = 1;
        for (int i = 0; i < str.length(); i++) {
            sum += p * getChar(str.charAt(i));
            p *= 5;
        }
        return sum;
    }

    public static int h1(int key) {
        return key % M;
    }

    public static int h2(int key) {
        return 1 + (key % (M - 1));
    }

    public static boolean find(String[] H, String str) {
        int key = (int) getKey(str);
        int hash = (h1(key) + 0 * h2(key)) % M;
        while (true) {
            if (H[hash].equals(str)) return true;
            else if (H[hash].equals("")) return false;
            hash = (hash + 1) % M;
        }
    }

    public static void insert(String[] H, String str) {
        int key = (int) getKey(str);
        int hash = (h1(key) + 0 * h2(key)) % M;
        while (true) {
            if (H[hash].equals(str)) return;
            else if (H[hash].equals("")) {
                H[hash] = str;
                return;
            }
            hash = (hash + 1) % M;
        }
    }
}
