
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
        }
        int tmpSum = 0;
        int rs = 0;
        for (int i = 0; i < n; i++) {
            tmpSum += l[i];
            if (tmpSum <= x) {
                rs = i + 2;
            } else if (tmpSum > x) {
                break;
            }
        }
        System.out.println(rs);
    }
}

