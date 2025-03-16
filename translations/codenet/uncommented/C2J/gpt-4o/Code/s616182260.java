import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[][] c = new int[3][3];
        int[] a = new int[3];
        int[] b = new int[3];

        for (int i = 0; i < 3; i++) {
            c[i][0] = scanner.nextInt();
            c[i][1] = scanner.nextInt();
            c[i][2] = scanner.nextInt();
        }

        a[0] = 0;
        for (int i = 0; i < 3; i++) {
            b[i] = c[0][i];
        }

        for (int i = 1; i < 3; i++) {
            a[i] = c[i][0] - b[0];
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (c[i][j] != a[i] + b[j]) {
                    System.out.println("No");
                    return;
                }
            }
        }
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
