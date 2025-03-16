
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int s = sc.nextInt();
        int f = sc.nextInt();
        int t = sc.nextInt();
        int l = sc.nextInt();
        int r = sc.nextInt();
        int k = 1;
        int i = 1;
        int j = s;
        String res = "";
        if (s < f) {
            char c = 'R';
            int d = 1;
        } else {
            char c = 'L';
            int d = -1;
        }
        while (j != f) {
            if (i > t && k < m) {
                t = sc.nextInt();
                l = sc.nextInt();
                r = sc.nextInt();
                k++;
            }
            if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
                res += "X";
            } else {
                res += c;
                j += d;
            }
            i++;
        }
        System.out.println(res);
    }
}

