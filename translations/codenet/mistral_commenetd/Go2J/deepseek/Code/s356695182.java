import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int len = 5;
        int[] l = new int[len];
        for (int i = 0; i < len; i++) {
            l[i] = scanner.nextInt();
        }
        System.out.println(Math.min(pattern1(l), Math.min(pattern2(l), pattern3(l))));
    }

    public static int pattern1(int[] l) {
        return (l[0] * l[3]) + (l[1] * l[4]);
    }

    public static int pattern2(int[] l) {
        int maxNum = Math.max(l[3], l[4]);
        return 2 * l[2] * maxNum;
    }

    public static int pattern3(int[] l) {
        int minNum = Math.min(l[3], l[4]);
        return 2 * l[2] * minNum + doch(l);
    }

    public static int doch(int[] l) {
        if (l[3] > l[4]) {
            return l[0] * (l[3] - l[4]);
        } else {
            return l[1] * (l[4] - l[3]);
        }
    }
}
