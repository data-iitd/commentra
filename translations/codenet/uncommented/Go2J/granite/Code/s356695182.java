
import java.util.Scanner;

public class s356695182{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] l = new int[5];
        for (int i = 0; i < 5; i++) {
            l[i] = sc.nextInt();
        }
        int n1 = pattern1(l);
        int n2 = pattern2(l);
        int n3 = pattern3(l);
        int min = Math.min(n1, Math.min(n2, n3));
        System.out.println(min);
    }

    public static int pattern1(int[] l) {
        int n = (l[0] * l[3]) + (l[1] * l[4]);
        return n;
    }

    public static int pattern2(int[] l) {
        int n = 2 * l[2] * Math.max(l[3], l[4]);
        return n;
    }

    public static int pattern3(int[] l) {
        int n = 2 * l[2] * Math.min(l[3], l[4]) + doch(l);
        return n;
    }

    public static int doch(int[] l) {
        if (l[3] > l[4]) {
            return l[0] * (l[3] - l[4]);
        } else {
            return l[1] * (l[4] - l[3]);
        }
    }
}

