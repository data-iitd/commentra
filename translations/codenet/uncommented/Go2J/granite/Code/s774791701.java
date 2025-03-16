
import java.util.Scanner;

public class s774791701{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        int price = 700;
        for (char c : s.toCharArray()) {
            if (c == 'o') {
                price += 100;
            }
        }
        System.out.println(price);
    }
}
// 