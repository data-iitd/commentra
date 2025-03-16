import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (a < 2) {
                System.out.println(0);
            } else {
                System.out.println(a - 2);
            }
        }
    }
}
