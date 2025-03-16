
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if (a < 2) {
                System.out.println(0);
            } else {
                System.out.println(a - 2);
            }
        }
    }
}
