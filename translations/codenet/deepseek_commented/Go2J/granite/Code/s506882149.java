
import java.util.Scanner;

public class s506882149{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int a = scanner.nextInt();
        scanner.close();

        int result = comp(x, a);
        System.out.println(result);
    }

    public static int comp(int x, int a) {
        if (x < a) {
            return 0;
        }
        return 10;
    }
}

