import java.util.Scanner;

class Data {
    int n, m;
    String[] nImg, mImg;

    public Data(int n, int m, String[] nImg, String[] mImg) {
        this.n = n;
        this.m = m;
        this.nImg = nImg;
        this.mImg = mImg;
    }

    public boolean exist() {
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                if (match(i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean match(int x, int y) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (nImg[x + i].charAt(y + j) != mImg[i].charAt(j)) {
                    return false;
                }
            }
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        Data d = newData();
        if (d.exist()) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static Data newData() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        String[] nImg = load(n, scanner);
        String[] mImg = load(m, scanner);
        return new Data(n, m, nImg, mImg);
    }

    public static String[] load(int cnt, Scanner scanner) {
        String[] ret = new String[cnt];
        for (int i = 0; i < cnt; i++) {
            ret[i] = scanner.next();
        }
        return ret;
    }
}

// <END-OF-CODE>
