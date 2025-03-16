
import java.util.Scanner;

public class s356695182{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] l = new int[5];
        for (int i = 0; i < 5; i++) {
            l[i] = scanner.nextInt();
        }
        int n1 = (l[0] * l[3]) + (l[1] * l[4]);
        int n2 = 2 * l[2] * Math.max(l[3], l[4]);
        int n3 = 2 * l[2] * Math.min(l[3], l[4]) + doch(l);
        int min = Math.min(n1, Math.min(n2, n3));
        System.out.println(min);
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