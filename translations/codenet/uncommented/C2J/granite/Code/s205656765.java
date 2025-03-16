
import java.util.Scanner;

public class s205656765{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int i = 0;
        int j = 0;
        int k = 0;
        int kosu = 0;

        X = X / 50;

        for (i = 0; i <= A; i++) {
            for (j = 0; j <= B; j++) {
                for (k = 0; k <= C; k++) {
                    if (X == (10 * i) + (2 * j) + k) {
                        kosu++;
                    }
                }
            }
        }

        System.out.println(kosu);
    }
}
