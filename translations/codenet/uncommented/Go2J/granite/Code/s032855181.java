
import java.util.Scanner;

public class s032855181{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();

        if (x == 2 || y == 2) {
            System.out.println("No");
            return;
        }

        String xg = group(x);
        String yg = group(y);

        if (xg.equals(yg)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    public static String group(int n) {
        if (n == 4 || n == 6 || n == 9 || n == 11) {
            return "B";
        } else {
            return "A";
        }
    }
}

