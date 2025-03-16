
import java.util.Scanner;

public class s861455616{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        if (s.length() >= 4 && s.substring(0, 4).equals("YAKI")) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
// 