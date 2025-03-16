
import java.util.Scanner;

public class s394238127{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] c = new int[3][3];
        int[] a = new int[3];
        int[] b = new int[3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = scanner.nextInt();
            }
        }

        b[0] = c[0][0] - a[0];
        b[1] = c[0][1] - a[0];
        b[2] = c[0][2] - a[0];
        a[1] = c[1][0] - c[0][0];
        a[2] = c[2][0] - c[0][0];
        if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
            a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

Translate the above Java code to C++ and end with comment "