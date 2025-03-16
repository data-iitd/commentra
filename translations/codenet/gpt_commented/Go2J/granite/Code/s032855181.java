
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

        String xGroup = group(x);
        String yGroup = group(y);

        if (xGroup.equals(yGroup)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static String group(int n) {
        if (n == 4 || n == 6 || n == 9 || n == 11) {
            return "B";
        } else {
            return "A";
        }
    }
}

