
import java.util.Scanner;

public class s187065108{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int r = scanner.nextInt();
        int D = scanner.nextInt();
        int x = scanner.nextInt();
        for (int i = 1; i <= 10; i++) {
            x = r * x - D;
            System.out.println(x);
        }
    }
}
