
import java.util.Scanner;

public class s356695182{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] l = new int[5];
        for (int i = 0; i < 5; i++) {
            l[i] = scanner.nextInt();
        }
        int min = Math.min(pattern1(l), Math.min(pattern2(l), pattern3(l)));
        System.out.println(min);
    }

    public static int pattern1(int[] l) {
        return (l[0] * l[3]) + (l[1] * l[4]);
    }

    public static int pattern2(int[] l) {
        return 2 * l[2] * Math.max(l[3], l[4]);
    }

    public static int pattern3(int[] l) {
        return 2 * l[2] * Math.min(l[3], l[4]) + doch(l);
    }

    public static int doch(int[] l) {
        if (l[3] > l[4]) {
            return l[0] * (l[3] - l[4]);
        } else {
            return l[1] * (l[4] - l[3]);
        }
    }
}

// 