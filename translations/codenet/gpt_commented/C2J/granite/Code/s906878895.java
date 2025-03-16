
import java.util.Scanner;

public class s906878895{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int x = a + b;
            int w = 0;
            while (x > 0) {
                w++;
                x /= 10;
            }
            System.out.println(w);
        }
    }
}
