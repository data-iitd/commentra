
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[] nImg = new String[n];
        String[] mImg = new String[m];
        for (int i = 0; i < n; i++) {
            nImg[i] = sc.next();
        }
        for (int i = 0; i < m; i++) {
            mImg[i] = sc.next();
        }
        if (exist(nImg, mImg)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static boolean exist(String[] nImg, String[] mImg) {
        for (int i = 0; i <= nImg.length - mImg.length; i++) {
            for (int j = 0; j <= nImg.length - mImg.length; j++) {
                if (match(nImg, mImg, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static boolean match(String[] nImg, String[] mImg, int x, int y) {
        for (int i = 0; i < mImg.length; i++) {
            for (int j = 0; j < mImg.length; j++) {
                if (!nImg[x + i].substring(y + j, y + j + 1).equals(mImg[i].substring(j, j + 1))) {
                    return false;
                }
            }
        }
        return true;
    }
}

