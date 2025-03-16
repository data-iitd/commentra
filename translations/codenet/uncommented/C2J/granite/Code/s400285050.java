
import java.util.Scanner;

public class s400285050{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int z = you(x, y);
        System.out.println(z);
    }

    public static int you(int x, int y) {
        int z;
        while (true) {
            z = x % y;
            x = y;
            y = z;
            if (y <= 0) break;
        }
        return x;
    }
}
// END-OF-CODE