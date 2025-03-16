import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int result = Math.max(x + y - 3 + ((y - x) % 3 > 0 ? 1 : 0), 0);
        System.out.println(result);
    }
}
