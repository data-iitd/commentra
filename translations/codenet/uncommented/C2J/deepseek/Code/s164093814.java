public class Main {
    static final int M = 1046527;
    static final int L = 14;
    static String[] H = new String[M];

    static int getChar(char ch) {
        if (ch == 'A') return 1;
        else if (ch == 'C') return 2;
        else if (ch == 'G') return 3;
        else if (ch == 'T') return 4;
        return 0;
    }

    static long getKey(String str) {
        long sum = 0, p = 1;
        for (int i = 0; i < str.length(); i++) {
            sum += p * (getChar(str.charAt(i)));
            p *= 5;
        }
        return sum;
    }

    static int h1(int key) {
        return key % M;
    }

    static int h2(int key) {
        return 1 + (key % (M - 1));
    }

    static boolean find(String str) {
        int i, hash, key;
        key = (int) getKey(str);
        i = 0;
        while (true) {
            hash = (h1(key) + i * h2(key)) % M;
            if (H[hash] != null && H[hash].equals(str)) return true;
            else if (H[hash] == null) return false;
            i++;
        }
    }

    static boolean insert(String str) {
        int i, hash, key;
        key = (int) getKey(str);
        i = 0;
        while (true) {
            hash = (h1(key) + i * h2(key)) % M;
            if (H[hash] != null && H[hash].equals(str)) return true;
            else if (H[hash] == null) {
                H[hash] = str;
                return false;
            }
            i++;
        }
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline left-over

        for (int i = 0; i < M; i++) H[i] = "";

        for (int i = 0; i < n; i++) {
            String com = scanner.next();
            String str = scanner.next();

            if (com.equals("i")) {
                insert(str);
            } else {
                if (find(str)) {
                    System.out.println("yes");
                } else {
                    System.out.println("no");
                }
            }
        }
    }
}
