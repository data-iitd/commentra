import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int xt = -1, yt = -1;

        int[][] a = {
            {1, 3, 5, 7, 8, 10, 12},
            {4, 6, 9, 11},
            {2}
        };

        for (int i = 0; i < a.length; i++) {
            for (int n : a[i]) {
                if (x == n) {
                    xt = i;
                }
                if (y == n) {
                    yt = i;
                }
            }
        }

        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// <END-OF-CODE>
