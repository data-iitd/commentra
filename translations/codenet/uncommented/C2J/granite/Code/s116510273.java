
import java.util.Scanner;

public class s116510273{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String mes = scanner.nextLine();
        System.out.printf("%c%lu%c\n", mes.charAt(0), mes.length() - 2, mes.charAt(mes.length() - 1));
    }
}
// 