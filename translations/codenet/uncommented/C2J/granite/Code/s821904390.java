
import java.util.Scanner;

public class s821904390{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int in = scanner.nextInt();

        int h = in / 3600;
        in %= 3600;

        int m = in / 60;
        in %= 60;

        int s = in;

        System.out.printf("%d:%d:%d\n", h, m, s);
    }
}
