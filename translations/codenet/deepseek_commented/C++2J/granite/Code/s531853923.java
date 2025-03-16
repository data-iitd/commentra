
import java.util.Scanner;

public class s531853923{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();
        if (a * b % 2 == 1 && (c + d) % 2 == 1) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}
