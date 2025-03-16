import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        if ((100 * a + 10 * b + c) % 4 == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
