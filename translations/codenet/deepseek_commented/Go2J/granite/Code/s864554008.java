
import java.util.Scanner;

public class s864554008{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        String[] nImg = new String[n];
        String[] mImg = new String[m];
        for (int i = 0; i < n; i++) {
            nImg[i] = scanner.next();
        }
        for (int i = 0; i < m; i++) {
            mImg[i] = scanner.next();
        }
        Data data = new Data(n, m, nImg, mImg);
        if (data.exist()) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

class Data {
    private int n;
    private int m;
    private String[] nImg;
    private String[] mImg;

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

    private boolean match(int x, int y) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (!nImg[x + i].equals(mImg[i].charAt(j))) {
                    return false;
                }
            }
        }
        return true;
    }
}

