
import java.util.Scanner;

public class codeforces_581_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        scanner.close();

        int min = Math.min(a, b);
        int halfDiff = (Math.max(a, b) - min) / 2;

        System.out.println(min + " " + halfDiff);
    }
}
